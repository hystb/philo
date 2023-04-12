/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:22 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/12 14:13:26 by nmilan           ###   ########.fr       */
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
	long long	should_dead;
	int			j;

	j = -1;
	should_dead = game->philo[i].time_last_eat + \
	game->time_to_die + game->first_time;
	if (should_dead <= time)
	{
		while (++j < game->nb_philo)
			game->philo[j].death = 1;
		usleep(100);
		print_philo(game->philo[i].id, DIE, game, 1);
		return (1);
	}
	return (0);
}

void	control_death(t_data *game, int i)
{
	int	nb_eat_succes;

	while (1)
	{
		usleep(100);
		nb_eat_succes = game->nb_time_eat == 0;
		lock_philo(game, 0);
		i = 0;
		while (i < game->nb_philo)
		{
			if (death_checker(i, get_time(), game))
			{
				unlock_philo(game, 0);
				return ;
			}
			if (game->nb_time_eat == -1
				|| game->philo[i].time_have_eat < game->nb_time_eat)
				nb_eat_succes++;
			i++;
		}
		unlock_philo(game, 0);
		if (nb_eat_succes == 0)
			return ;
	}
}
