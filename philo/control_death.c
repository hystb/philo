/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:22 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/10 16:57:07 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_philo(t_data *game, int i)
{
	while (i < game->nb_philo)
	{
		pthread_mutex_lock(&(game->philo[i].meal_check));
		i++;
	}
	return ;
}

void	unlock_philo(t_data *game, int i)
{
	while (i < game->nb_philo)
	{
		pthread_mutex_unlock(&(game->philo[i].meal_check));
		i++;
	}
	return ;
}

int	death_checker(int i, long time, t_data *game)
{
	long	should_dead;

	should_dead = game->philo[i].time_last_eat + \
	game->time_to_die + game->first_time;
	if (should_dead <= time)
	{
		print_philo(game->philo[i].id, DIE, game, 1);
		return (1);
	}
	return (0);
}

void	control_death(t_data *game, int i)
{
	while (1)
	{
		lock_philo(game, 0);
		i = 0;
		while (i < game->nb_philo)
		{
			if (death_checker(i, get_time(), game))
			{
				unlock_philo(game, 0);
				return ;
			}
			i++;
		}
		unlock_philo(game, 0);
	}
}
