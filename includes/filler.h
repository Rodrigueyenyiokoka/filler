/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:18:13 by oyenyi-           #+#    #+#             */
/*   Updated: 2018/08/20 12:59:59 by oyenyi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_player
{
	char		player_nbr;
	char		letter;
	char		current_letter;

}				t_player;

typedef struct	s_map_piece
{
	int			x_col;
	int			y_row;
	int			x_pce;
	int			y_pce;
	int			x_place;
	int			x_place1;
	int			y_place;
	int			y_place1;
	int			place_flag;
	int			place_flag1;
	int			modulo;
	int			p_left_start;
	int			p_top_start;
	int			p_bottom_end;
	int			p_right_end;
	int			add_nbr;
	int			os_nbr;
	int			xs_nbr;
	int			tmp_os;
	int			tmp_xs;
	int			place_coord_x;
	int			place_coord_y;
	int			piece_y;
	int			piece_x;
	int			map_x;
	int			map_y;

	char		**map;
	char		**piece;
	char		**tmp_map;

}				t_map_info;

void			player_nbr(t_player *player);
void			m_size(t_map_info *map);
void			map_info(t_map_info *read_map_info);
void			save_map_tmp(t_map_info *read_tmp_info);
void			token_info(t_map_info *read_piece_info);
void			token_size(t_map_info *piece);
void			initial_piece(t_map_info *info);
void			initial_piece1(t_map_info *info);
void			place_token(t_map_info *info, t_player *me);
void			get_shape_nbr(t_map_info *p_info);
void			letter_nbr(t_map_info *p_info);
void			letter_tmp_nbr(t_map_info *p_info);
void			send_coord(t_map_info *info);
void			init_struct(t_map_info *info);
void			token_left_side(t_map_info *info);
void			token_top_side(t_map_info *info);
void			token_right_side(t_map_info *info);
void			token_bottom_side(t_map_info *info);
void			trim_token_map(t_map_info *info);
void			info_algo(t_map_info *info, t_player *me);
void			token_algo(t_map_info *info, t_player *me);
void			map_algo(t_map_info *info);
void			place_token_algo(t_map_info *info, t_player *me);
void			place_token_algo1(t_map_info *info, t_player *me);
void			algorithm(t_map_info *info, t_player *me);
void			algorithm1(t_map_info *info, t_player *me);
void			place_token_rev(t_map_info *info, t_player *me);
void			rev_algo2(t_map_info *info, t_player *me);
void			rev_algo4(t_map_info *info, t_player *me);
void			place_token_rev1(t_map_info *info, t_player *me);
void			rev_algo2_1(t_map_info *info, t_player *me);
void			rev_algo4_1(t_map_info *info, t_player *me);
int				rev_move(t_map_info *info);
int				rev_move1(t_map_info *info);
int				check_placement(t_map_info *piece_info, t_player *shape);
int				move_token(t_map_info *info);
int				rev_move(t_map_info *info);
#endif
