/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:44 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/13 14:53:22 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	died(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_check);
	if (philo->death)
	{
		pthread_mutex_unlock(&philo->meal_check);
		return (0);
	}
	pthread_mutex_unlock(&philo->meal_check);
	return (1);
}

void	count_eating(t_philo *philo)
{
	if (philo->time_have_eat != -1)
		philo->time_have_eat++;
	pthread_mutex_unlock(&philo->meal_check);
}

int	philo_eat(t_philo *phi, pthread_mutex_t **fork, t_data *game)
{
	//usleep(600);
	pthread_mutex_lock(fork[0]);
	print_philo(phi->id, FORK, phi->game, 0);
	if (game->nb_philo != 1)
	{	
		pthread_mutex_lock(fork[1]);
		print_philo(phi->id, FORK, phi->game, 0);
		if (!died(phi))
		{
			pthread_mutex_unlock(fork[0]);
			return (pthread_mutex_unlock(fork[1]), 1);
		}
		print_philo(phi->id, EAT, phi->game, 0);
		pthread_mutex_lock(&phi->meal_check);
		phi->time_last_eat = get_time() - game->first_time;
		count_eating(phi);
		make_wait(game->time_to_eat, phi);
		pthread_mutex_unlock(fork[1]);
	}
	pthread_mutex_unlock(fork[0]);
	return (1);
}

void	*start_actions(void *philo)
{
	t_philo			*phi;
	t_data			*game;
	pthread_mutex_t	*fork[2];

	phi = philo;
	game = phi->game;
	fork[0] = &game->forks[phi->left_fork_id];
	fork[1] = &game->forks[phi->right_fork_id];
	print_philo(phi->id, THINK, phi->game, 0);
	if (phi->id % 2 == 1)
		make_wait(game->time_to_eat, phi);
	while (died(phi) && (phi->time_have_eat < game->nb_time_eat
			|| game->nb_time_eat == -1))
	{
		philo_eat(philo, fork, game);
		if (game->nb_philo == 1)
			return (NULL);
		if ((phi->time_have_eat < game->nb_time_eat || game->nb_time_eat == -1))
			print_philo(phi->id, SLEEP, phi->game, 2);
		if (died(phi) && (phi->time_have_eat < game->nb_time_eat
				|| game->nb_time_eat == -1))
			print_philo(phi->id, THINK, phi->game, 0);
	}
	return (NULL);
}

int	game(t_data *game, int i, t_philo *philo)
{
	philo = game->philo;
	game->first_time = (get_time());
	while (++i < game->nb_philo)
	{
		if (pthread_create(&(philo[i].th_id), NULL, start_actions, &philo[i]))
		{
			while (i >= 0)
				pthread_join(philo[--i].th_id, NULL);
			return (1);
		}
	}
	control_death(game, 0);
	i = -1;
	while (++i < game->nb_philo)
		pthread_join(philo[i].th_id, NULL);
	return (0);
}
