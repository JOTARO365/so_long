/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define TILE		64
# define WIN_W		960
# define WIN_H		576

# define IMG_WALL	0
# define IMG_FLOOR	1
# define IMG_PLAY	2
# define IMG_COIN	3
# define IMG_EXIT	4

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img[5];
	t_map	map;
	int		px;
	int		py;
	int		collected;
	int		moves;
	int		cam_x;
	int		cam_y;
}	t_game;

/* parse.c */
void	parse_map(t_game *game, char *file);

/* validate.c */
void	validate_map(t_game *game);

/* render.c */
void	load_textures(t_game *game);
void	render_map(t_game *game);

/* player.c */
int		handle_key(int key, t_game *game);
int		handle_close(t_game *game);

/* error.c */
void	error_exit(t_game *game, char *msg);

/* free.c */
void	free_game(t_game *game);

#endif
