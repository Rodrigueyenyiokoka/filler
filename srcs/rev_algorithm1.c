/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_algorithm1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:34:06 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/20 16:18:52 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	place_token_rev(t_map_info *info, t_player *me)
{
	while (info->piece_y >= info->p_top_start)
	{
		info->place_flag = (info->y_place - (info->p_bottom_end -
					info->p_top_start + 1) < 0 ? 2 : 0);
		if (info->place_flag == 2)
			return ;
		info->map_x = info->x_place1;
		info->piece_x = info->p_left_start;
		while (info->piece_x <= info->p_right_end)
		{
			info->place_flag = (info->x_place1 + (info->p_right_end -
						info->p_left_start + 1) > info->x_col ? 1 : 0);
			if (info->place_flag == 1)
				return ;
			if (info->piece[info->piece_y][info->piece_x] != '.')
				info->tmp_map[info->map_y][info->map_x] = me->letter;
			info->place_coord_x = info->x_place1 - info->p_left_start;
			info->place_coord_y = info->map_y - info->p_top_start;
			info->map_x++;
			info->piece_x++;
		}
		info->map_y--;
		info->piece_y--;
	}
}

int		rev_move(t_map_info *info)
{
	if (info->place_flag == 1)
	{
		info->y_place--;
		info->x_place1 = 0;
	}
	else if (info->place_flag == 2)
		return (1);
	else
		info->x_place1++;
	return (0);
}

void	rev_algo2(t_map_info *info, t_player *me)
{
	save_map_tmp(info);
	get_shape_nbr(info);
	initial_piece(info);
	place_token_rev(info, me);
	letter_nbr(info);
	letter_tmp_nbr(info);
}

void	rev_algo4(t_map_info *info, t_player *me)
{
	rev_algo2(info, me);
	if (!(check_placement(info, me)))
	{
		send_coord(info);
		info->modulo++;
		info->y_place = info->y_row - 1;
		map_algo(info);
	}
	else
	{
		if (!rev_move(info))
			save_map_tmp(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}

void	algorithm1(t_map_info *info, t_player *me)
{
	if (me->letter == 'X')
	{
		if (info->modulo % 2)
			place_token_algo(info, me);
		else
			place_token_algo1(info, me);
	}
	else
	{
		if (info->modulo % 2)
			rev_algo4(info, me);
		else
			rev_algo4_1(info, me);
	}
}
