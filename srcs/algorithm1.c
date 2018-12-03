/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:31:15 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/20 11:48:57 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	init_struct(t_map_info *info)
{
	info->x_place = 0;
	info->y_place = 0;
	info->modulo = 0;
	info->place_flag = 0;
	info->add_nbr = 0;
	info->os_nbr = 0;
	info->xs_nbr = 0;
	info->tmp_os = 0;
	info->tmp_xs = 0;
	info->place_coord_x = 0;
	info->place_coord_y = 0;
}

void	info_algo(t_map_info *info, t_player *me)
{
	player_nbr(me);
	m_size(info);
	map_info(info);
	token_size(info);
	token_info(info);
	trim_token_map(info);
	save_map_tmp(info);
}

void	token_algo(t_map_info *info, t_player *me)
{
	save_map_tmp(info);
	get_shape_nbr(info);
	initial_piece(info);
	place_token(info, me);
	letter_nbr(info);
	letter_tmp_nbr(info);
}

void	map_algo(t_map_info *info)
{
	free(info->map);
	map_info(info);
	info->x_pce = 0;
	info->y_pce = 0;
	token_size(info);
	free(info->piece);
	token_info(info);
	trim_token_map(info);
}

void	place_token_algo(t_map_info *info, t_player *me)
{
	token_algo(info, me);
	if (!(check_placement(info, me)))
	{
		send_coord(info);
		info->modulo++;
		info->y_place = info->y_row - 1;
		map_algo(info);
	}
	else
	{
		if (!move_token(info))
			save_map_tmp(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}
