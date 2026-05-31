/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	game_loop(t_game *game)
{
	usleep(16000);
	game->grav_tick++;
	if (game->grav_tick >= GRAV_SPEED)
	{
		game->grav_tick = 0;
		apply_gravity(game);
	}
	game->move_tick++;
	if (game->move_tick >= MOVE_SPEED)
	{
		game->move_tick = 0;
		player_move_tick(game);
	}
	update_enemies(game);
	game->anim_tick++;
	if (game->anim_tick >= ANIM_SPEED)
	{
		game->anim_tick = 0;
		game->anim_frame = 1 - game->anim_frame;
		render_map(game);
	}
	return (0);
}

static void	init_mlx(t_game *game)
{
	int	win_w;
	int	win_h;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "mlx_init failed.");
	win_w = game->map.width * TILE;
	win_h = game->map.height * TILE;
	if (win_w > WIN_W)
		win_w = WIN_W;
	if (win_h > WIN_H)
		win_h = WIN_H;
	game->win = mlx_new_window(game->mlx, win_w, win_h, "So Long");
	if (!game->win)
		error_exit(game, "mlx_new_window failed.");
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Error\nUsage: ./so_long <map.ber>\n", 33);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	parse_map(&game, av[1]);
	validate_map(&game);
	init_mlx(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 3, 1L << 1, handle_key_release, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
