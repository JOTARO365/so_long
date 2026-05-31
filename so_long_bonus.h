/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define TILE		64
# define WIN_W		960
# define WIN_H		576
# define GRAV_SPEED	1
# define ANIM_SPEED	18
# define MOVE_SPEED	8
# define JUMP_V		20
# define GRAVITY_V	1
# define MAX_FALL_V	20
# define MAX_ENEMIES	64
# define ENEMY_SPEED	10

# define IMG_WALL	0
# define IMG_FLOOR	1
# define IMG_PLAY	2
# define IMG_PLAY2	3
# define IMG_COIN	4
# define IMG_COIN2	5
# define IMG_EXIT	6
# define IMG_ENEMY	7

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_SPACE	32
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

typedef struct s_enemy
{
	int	x;
	int	y;
	int	dir;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img[8];
	t_map	map;
	int		px;
	int		py;
	int		py_px;
	int		collected;
	int		moves;
	int		grav_tick;
	int		anim_tick;
	int		anim_frame;
	int		cam_x;
	int		cam_y;
	int		vy;
	int		key_left;
	int		key_right;
	int		move_tick;
	t_enemy	enemies[MAX_ENEMIES];
	int		n_enemies;
	int		enemy_tick;
}	t_game;

/* parse_bonus.c */
void	parse_map(t_game *game, char *file);

/* validate_bonus.c */
void	validate_map(t_game *game);

/* render_bonus.c */
void	load_textures(t_game *game);
void	render_map(t_game *game);

/* player_bonus.c */
int		handle_key(int key, t_game *game);
int		handle_key_release(int key, t_game *game);
int		handle_close(t_game *game);
void	player_move_tick(t_game *game);

/* physics_bonus.c */
void	apply_gravity(t_game *game);

/* enemy_bonus.c */
void	add_enemy(t_game *game, int x, int y);
void	update_enemies(t_game *game);
void	draw_enemies(t_game *game);

/* error_bonus.c */
void	error_exit(t_game *game, char *msg);

/* free_bonus.c */
void	free_game(t_game *game);

#endif
