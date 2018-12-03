/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:37:31 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/18 09:21:07 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	token_left_side(t_map_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->x_pce)
	{
		y = 0;
		while (y < info->y_pce)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_left_start = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	token_top_side(t_map_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->y_pce)
	{
		x = 0;
		while (x < info->x_pce)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_top_start = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	token_right_side(t_map_info *info)
{
	int	x;
	int	y;

	x = info->x_pce - 1;
	while (x >= 0)
	{
		y = info->y_pce - 1;
		while (y >= 0)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_right_end = x;
				return ;
			}
			y--;
		}
		x--;
	}
}

void	token_bottom_side(t_map_info *info)
{
	int	x;
	int	y;

	y = info->y_pce - 1;
	while (y >= 0)
	{
		x = info->x_pce - 1;
		while (x >= 0)
		{
			if (info->piece[y][x] == '*')
			{
				info->p_bottom_end = y;
				return ;
			}
			x--;
		}
		y--;
	}
}

void	trim_token_map(t_map_info *info)
{
	token_bottom_side(info);
	token_left_side(info);
	token_right_side(info);
	token_top_side(info);
}
