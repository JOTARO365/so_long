/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:00:00 by wiaon-in          #+#    #+#             */
/*   Updated: 2026/05/23 12:00:00 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.grid[0][i] != '1'
			|| game->map.grid[game->map.height - 1][i] != '1')
			error_exit(game, "Map is not surrounded by walls.");
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i][0] != '1'
			|| game->map.grid[i][game->map.width - 1] != '1')
			error_exit(game, "Map is not surrounded by walls.");
		i++;
	}
}

static char	**copy_grid(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		error_exit(game, "Memory allocation failed.");
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
			error_exit(game, "Memory allocation failed.");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **grid, int x, int y)
{
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y);
	flood_fill(grid, x - 1, y);
	flood_fill(grid, x, y + 1);
	flood_fill(grid, x, y - 1);
}

static int	check_reachable(t_game *game, char **copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	validate_map(t_game *game)
{
	char	**copy;
	int		i;
	int		ok;

	check_walls(game);
	copy = copy_grid(game);
	flood_fill(copy, game->px, game->py);
	ok = check_reachable(game, copy);
	i = 0;
	while (i < game->map.height)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	if (ok)
		error_exit(game, "No valid path to exit or collectibles.");
}
