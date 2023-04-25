/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:48:54 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/25 11:40:47 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	swap_fork(t_philo *philo)
{
	int	swap;

	if (philo->id % 2)
	{
		swap = philo->left_fork_id;
		philo->left_fork_id = philo->right_fork_id;
		philo->right_fork_id = swap;
	}
	return ;
}

void	give_fork(int **usd, pthread_mutex_t **frk, t_philo *phi, t_data *game)
{
	frk[0] = &game->forks[phi->left_fork_id];
	frk[1] = &game->forks[phi->right_fork_id];
	usd[0] = &game->is_used[phi->left_fork_id];
	usd[1] = &game->is_used[phi->right_fork_id];
}

void	nxt_step(int **usd, pthread_mutex_t **fork, t_philo *phi, t_data *game)
{
	if (!died(phi))
		return ;
	print_philo(phi->id, EAT, phi->game, 0);
	pthread_mutex_lock(&phi->meal_check);
	phi->time_last_eat = get_time() - game->first_time;
	count_eating(phi);
	make_wait(game->time_to_eat, phi);
	pthread_mutex_lock(fork[0]);
	*usd[0] = 0;
	pthread_mutex_unlock(fork[0]);
	pthread_mutex_lock(fork[1]);
	*usd[1] = 0;
	pthread_mutex_unlock(fork[1]);
}

void	take_fork(int *used, int *taken, t_philo *phi, t_data *game)
{
	print_philo(phi->id, FORK, game, 0);
	*used = 1;
	*taken = 1;
}
