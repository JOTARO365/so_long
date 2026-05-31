/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img[IMG_WALL] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img[IMG_FLOOR] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img[IMG_PLAY] = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	game->img[IMG_PLAY2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player2.xpm", &w, &h);
	game->img[IMG_COIN] = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &w, &h);
	game->img[IMG_COIN2] = mlx_xpm_file_to_image(game->mlx,
			"textures/collect2.xpm", &w, &h);
	game->img[IMG_EXIT] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	game->img[IMG_ENEMY] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &w, &h);
	if (!game->img[IMG_WALL] || !game->img[IMG_FLOOR]
		|| !game->img[IMG_PLAY] || !game->img[IMG_PLAY2]
		|| !game->img[IMG_COIN] || !game->img[IMG_COIN2]
		|| !game->img[IMG_EXIT] || !game->img[IMG_ENEMY])
		error_exit(game, "Failed to load textures.");
}

static void	update_camera(t_game *game)
{
	int	max_cx;
	int	max_cy;

	game->cam_x = game->px - WIN_W / (2 * TILE);
	game->cam_y = game->py - WIN_H / (2 * TILE);
	max_cx = game->map.width - WIN_W / TILE;
	max_cy = game->map.height - WIN_H / TILE;
	if (game->cam_x < 0)
		game->cam_x = 0;
	if (game->cam_y < 0)
		game->cam_y = 0;
	if (max_cx > 0 && game->cam_x > max_cx)
		game->cam_x = max_cx;
	if (max_cy > 0 && game->cam_y > max_cy)
		game->cam_y = max_cy;
}

static void	render_tile(t_game *game, int x, int y)
{
	char	c;
	int		sx;
	int		sy;

	c = game->map.grid[y][x];
	sx = (x - game->cam_x) * TILE;
	sy = (y - game->cam_y) * TILE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[IMG_FLOOR], sx, sy);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img[IMG_WALL], sx, sy);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img[IMG_COIN + game->anim_frame], sx, sy);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img[IMG_EXIT], sx, sy);
}

static void	draw_move_count(t_game *game)
{
	char	*num;
	char	*str;

	num = ft_itoa(game->moves);
	if (!num)
		return ;
	str = ft_strjoin("Moves: ", num);
	free(num);
	if (!str)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, str);
	free(str);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	update_camera(game);
	max_x = game->cam_x + WIN_W / TILE;
	max_y = game->cam_y + WIN_H / TILE;
	y = game->cam_y;
	while (y < max_y && y < game->map.height)
	{
		x = game->cam_x;
		while (x < max_x && x < game->map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	draw_enemies(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img[IMG_PLAY + game->anim_frame],
		(game->px - game->cam_x) * TILE,
		game->py_px - game->cam_y * TILE);
	draw_move_count(game);
}
