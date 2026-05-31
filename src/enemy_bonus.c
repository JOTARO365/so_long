/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/31 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_enemy(t_game *game, int x, int y)
{
	if (game->n_enemies >= MAX_ENEMIES)
		error_exit(game, "Too many enemies in map.");
	game->enemies[game->n_enemies].x = x;
	game->enemies[game->n_enemies].y = y;
	game->enemies[game->n_enemies].dir = 1;
	game->n_enemies++;
	game->map.grid[y][x] = '0';
}

static int	blocked(t_game *game, int x, int y)
{
	if (x < 1 || x >= game->map.width - 1)
		return (1);
	if (game->map.grid[y][x] == '1')
		return (1);
	if (game->map.grid[y + 1][x] != '1')
		return (1);
	return (0);
}

static void	move_enemies(t_game *game)
{
	int	i;
	int	nx;

	i = 0;
	while (i < game->n_enemies)
	{
		nx = game->enemies[i].x + game->enemies[i].dir;
		if (blocked(game, nx, game->enemies[i].y))
			game->enemies[i].dir = -game->enemies[i].dir;
		else
			game->enemies[i].x = nx;
		i++;
	}
}

void	update_enemies(t_game *game)
{
	int	i;

	game->enemy_tick++;
	if (game->enemy_tick >= ENEMY_SPEED)
	{
		game->enemy_tick = 0;
		move_enemies(game);
	}
	i = 0;
	while (i < game->n_enemies)
	{
		if (game->enemies[i].x == game->px
			&& game->enemies[i].y == game->py)
		{
			ft_printf("You lose! Moves: %d\n", game->moves);
			free_game(game);
			exit(0);
		}
		i++;
	}
}

void	draw_enemies(t_game *game)
{
	int	i;
	int	sx;
	int	sy;

	i = 0;
	while (i < game->n_enemies)
	{
		sx = (game->enemies[i].x - game->cam_x) * TILE;
		sy = (game->enemies[i].y - game->cam_y) * TILE;
		mlx_put_image_to_window(game->mlx, game->win,
			game->img[IMG_ENEMY], sx, sy);
		i++;
	}
}
