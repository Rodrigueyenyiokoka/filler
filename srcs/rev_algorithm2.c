/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_algorithm2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:36:47 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/18 12:11:52 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	place_token_rev1(t_map_info *info, t_player *me)
{
	while (info->piece_y <= info->p_bottom_end)
	{
		info->place_flag = (info->y_place1 + (info->p_bottom_end -
					info->p_top_start + 1) > info->y_row ? 2 : 0);
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
			info->place_coord_y = info->y_place1 - info->p_top_start;
			info->map_x++;
			info->piece_x++;
		}
		info->map_y++;
		info->piece_y++;
	}
}

int		rev_move1(t_map_info *info)
{
	if (info->place_flag == 1)
	{
		info->y_place1++;
		info->x_place1 = 0;
	}
	else if (info->place_flag == 2)
		return (1);
	else
		info->x_place1++;
	return (0);
}

void	rev_algo2_1(t_map_info *info, t_player *me)
{
	save_map_tmp(info);
	get_shape_nbr(info);
	initial_piece1(info);
	place_token_rev1(info, me);
	letter_nbr(info);
	letter_tmp_nbr(info);
}

void	rev_algo4_1(t_map_info *info, t_player *me)
{
	rev_algo2_1(info, me);
	if (!(check_placement(info, me)))
	{
		send_coord(info);
		info->modulo++;
		info->y_place1 = 0;
		map_algo(info);
	}
	else
	{
		if (!rev_move1(info))
			save_map_tmp(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}

void	algorithm(t_map_info *info, t_player *me)
{
	while (1)
	{
		if (info->y_row == 15 || info->y_row == 24)
		{
			if (me->letter == 'O')
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
		else
			algorithm1(info, me);
	}
}
