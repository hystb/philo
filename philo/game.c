#include "philo.h"

int	died(t_data *game)
{
	pthread_mutex_lock(&game->died);
	if (game->death)
	{
		pthread_mutex_unlock(&game->died);
		return (0);
	}
	pthread_mutex_unlock(&game->died);
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
	print_philo(phi->id, FORK, phi->game, 0);
	pthread_mutex_lock(fork[1]);
	print_philo(phi->id, FORK, phi->game, 0);
	pthread_mutex_lock(&phi->meal_check);
	print_philo(phi->id, EAT, phi->game, 0);
	phi->time_last_eat = get_time();
	pthread_mutex_unlock(&phi->meal_check);
	count_eating(phi);
	make_wait(game->time_to_eat, game);
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
	if (phi->id % 2)
	{
		fork[0] = &game->forks[phi->right_fork_id];
		fork[1] = &game->forks[phi->left_fork_id];
	}
	else
	{
		fork[0] = &game->forks[phi->left_fork_id];
		fork[1] = &game->forks[phi->right_fork_id];
	}
	while (died(game) && (phi->time_have_eat < game->nb_time_eat
			|| game->nb_time_eat == -1))
	{
		philo_eat(philo, fork, game);
		if (phi->time_have_eat < game->nb_time_eat || game->nb_time_eat == -1)
			print_philo(phi->id, SLEEP, phi->game, 0);
		make_wait(500, game);
	}
	return (NULL);
}

int	game(t_data *game)
{
	int		i;
	t_philo	*philo;

	i = 0;
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
		pthread_join(philo[i].th_id, NULL);
		i++;
	}
	return (0);
}
