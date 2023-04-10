#include "philo.h"

int	died(t_philo *philo, int mutex)
{
	if (!mutex)
		pthread_mutex_lock(&philo->meal_check);
	if (philo->death)
	{
		if (!mutex)
			pthread_mutex_unlock(&philo->meal_check);
		return (0);
	}
	if (!mutex)
		pthread_mutex_unlock(&philo->meal_check);
	return (1);
}

void	count_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_check);
	if (philo->time_have_eat != -1)
		philo->time_have_eat++;
	pthread_mutex_unlock(&philo->meal_check);
}

int	philo_eat(t_philo *phi, pthread_mutex_t **fork, t_data *game)
{
	print_philo(phi->id, THINK, phi->game, 0);
	pthread_mutex_lock(fork[0]);
	if (!died(phi, 0))
		return (pthread_mutex_unlock(fork[0]), 1);
	print_philo(phi->id, FORK, phi->game, 0);
	pthread_mutex_lock(fork[1]);
	print_philo(phi->id, FORK, phi->game, 0);
	if (!died(phi, 0))
	{
		pthread_mutex_unlock(fork[0]);
		return (pthread_mutex_unlock(fork[1]), 1);
	}
	print_philo(phi->id, EAT, phi->game, 0);
	phi->time_last_eat = get_time();
	count_eating(phi);
	make_wait(game->time_to_eat);
	pthread_mutex_unlock(fork[0]);
	pthread_mutex_unlock(fork[1]);
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
	if (phi->id % 2)
	{
		fork[0] = &game->forks[phi->right_fork_id];
		fork[1] = &game->forks[phi->left_fork_id];
	}
	while (died(phi, 0) && (phi->time_have_eat < game->nb_time_eat
			|| game->nb_time_eat == -1))
	{
		philo_eat(philo, fork, game);
		if (phi->time_have_eat < game->nb_time_eat || game->nb_time_eat == -1)
		{
			print_philo(phi->id, SLEEP, phi->game, 0);
			make_wait(game->time_to_sleep);
		}
	}
	return (NULL);
}

int	game(t_data *game, int i, t_philo *philo)
{
	philo = game->philo;
	game->first_time = (get_time());
	while (i < game->nb_philo)
	{
		if (pthread_create(&(philo[i].th_id), NULL, start_actions, &philo[i]))
		{
			while (i >= 0)
				pthread_join(philo[--i].th_id, NULL);
			return (1);
		}
		i++;
	}
	i = 0;
	control_death(game, 0);
	while (i < game->nb_philo)
	{
		pthread_mutex_lock(&game->philo[i].meal_check);
		game->philo[i].death = 1;
		pthread_mutex_unlock(&game->philo[i].meal_check);
		i++;
	}
	i = 0;
	while (i++ < game->nb_philo)
		pthread_join(philo[i - 1].th_id, NULL);
	return (0);
}
