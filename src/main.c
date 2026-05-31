/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
