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

int	philo_eat(t_philo *phi, pthread_mutex_t **fork, t_data *game)
{
	print_philo(phi->id, THINK, phi->game, 0);
	pthread_mutex_lock(fork[0]);
	print_philo(phi->id, FORK, phi->game, 0);
	pthread_mutex_lock(fork[1]);
	print_philo(phi->id, FORK, phi->game, 0);
	print_philo(phi->id, EAT, phi->game, 0);
	pthread_mutex_lock(&phi->meal_check);
	phi->time_last_eat = get_time();
	pthread_mutex_unlock(&phi->meal_check);
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
		usleep(1000);
	}
	else
	{
		fork[0] = &game->forks[phi->left_fork_id];
		fork[1] = &game->forks[phi->right_fork_id];
	}
	while (died(game))
	{
		philo_eat(philo, fork, game);
	}
	return (NULL);
}

int	game(t_data *rules)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = rules->philo;
	rules->first_time = (get_time());
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(philo[i].th_id), NULL, start_actions, &philo[i]))
			return (1);
		i++;
	}
	i = 0;
	control_death(rules, 0);
	while (i < rules->nb_philo)
	{
		pthread_join(philo[i].th_id, NULL);
		i++;
	}
	free(rules->forks);
	free(rules->philo);
	return (0);
}
