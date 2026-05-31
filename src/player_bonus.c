/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

static void	try_move(t_game *game, int dx)
{
	int		nx;
	char	*cell;

	nx = game->px + dx;
	cell = &game->map.grid[game->py][nx];
	if (*cell == '1')
		return ;
	if (*cell == 'E' && game->collected < game->map.collectibles)
		return ;
	game->px = nx;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (*cell == 'C')
	{
		game->collected++;
		*cell = '0';
	}
	else if (*cell == 'E')
	{
		ft_printf("You win! Moves: %d\n", game->moves);
		free_game(game);
		exit(0);
	}
	render_map(game);
}

int	handle_key(int key, t_game *game)
{
	char	below;

	if (key == KEY_ESC)
	{
		free_game(game);
		exit(0);
	}
	if (key == KEY_A || key == KEY_LEFT)
		game->key_left = 1;
	else if (key == KEY_D || key == KEY_RIGHT)
		game->key_right = 1;
	below = game->map.grid[game->py + 1][game->px];
	if ((key == KEY_W || key == KEY_UP || key == KEY_SPACE)
		&& below == '1' && !game->vy)
		game->vy = -JUMP_V;
	return (0);
}

int	handle_key_release(int key, t_game *game)
{
	if (key == KEY_A || key == KEY_LEFT)
		game->key_left = 0;
	else if (key == KEY_D || key == KEY_RIGHT)
		game->key_right = 0;
	return (0);
}

void	player_move_tick(t_game *game)
{
	if (game->key_left)
		try_move(game, -1);
	else if (game->key_right)
		try_move(game, 1);
}
