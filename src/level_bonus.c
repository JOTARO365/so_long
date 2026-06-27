/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/31 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_start_level(char *file)
{
	int	i;
	int	n;
	int	last;

	i = 0;
	n = 0;
	last = 0;
	while (file[i])
	{
		if (file[i] >= '0' && file[i] <= '9')
		{
			n = n * 10 + (file[i] - '0');
			last = n;
		}
		else
			n = 0;
		i++;
	}
	return (last);
}

static char	*level_path(t_game *game, int n)
{
	char	*num;
	char	*tmp;
	char	*path;

	num = ft_itoa(n);
	if (!num)
		error_exit(game, "Memory allocation failed.");
	tmp = ft_strjoin("maps/level", num);
	free(num);
	if (!tmp)
		error_exit(game, "Memory allocation failed.");
	path = ft_strjoin(tmp, ".ber");
	free(tmp);
	if (!path)
		error_exit(game, "Memory allocation failed.");
	return (path);
}

static void	reset_level(t_game *game)
{
	game->collected = 0;
	game->n_enemies = 0;
	game->vy = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->grav_tick = 0;
	game->move_tick = 0;
	game->anim_tick = 0;
	game->anim_frame = 0;
	game->enemy_tick = 0;
	game->cam_x = 0;
	game->cam_y = 0;
	game->map.players = 0;
	game->map.collectibles = 0;
	game->map.exits = 0;
}

void	start_level(t_game *game)
{
	char	*path;

	path = level_path(game, game->level);
	free_grid(game->map.grid);
	game->map.grid = NULL;
	reset_level(game);
	parse_map(game, path);
	free(path);
	validate_map(game);
	open_window(game);
	render_map(game);
}

void	next_level(t_game *game)
{
	char	*path;
	int		fd;

	game->level++;
	path = level_path(game, game->level);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
	{
		ft_printf("You beat all levels! Moves: %d\n", game->moves);
		free_game(game);
		exit(0);
	}
	close(fd);
	start_level(game);
}
