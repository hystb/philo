#include "philo.h"

int	init_mutex(t_data *game)
{
	int	i;

	i = game->nb_philo - 1;
	game->forks = malloc(sizeof(pthread_mutex_t) * game->nb_philo);
	while (i >= 0)
	{
		if (pthread_mutex_init(&(game->forks[i]), NULL))
			return (2);
		i--;
	}
	pthread_mutex_init(&(game->writing), NULL);
	pthread_mutex_init(&(game->died), NULL);
	return (0);
}

void	init_philo(t_data *game)
{
	int	i;

	i = 0;
	game->philo = malloc(sizeof(t_philo) * game->nb_philo);
	while (i < game->nb_philo)
	{
		game->philo[i].id = i;
		game->philo[i].x_ate = 0;
		game->philo[i].left_fork_id = i;
		if (i == game->nb_philo - 1)
			game->philo[i].right_fork_id = 0;
		else
			game->philo[i].right_fork_id = i + 1;
		game->philo[i].time_last_eat = 0;
		pthread_mutex_init(&game->philo[i].meal_check, NULL);
		game->philo[i].game = game;
		game->philo[i].time_last_eat = 0;
		i++;
	}
}

int	init_game(char **argv, t_data *game)
{
	game->nb_philo = ft_atoi(argv[1], 0);
	game->time_to_die = ft_atoi(argv[2], 0);
	game->time_to_eat = ft_atoi(argv[3], 0);
	game->time_to_sleep = ft_atoi(argv[4], 0);
	game->death = 0;
	if (argv[5])
	{
		game->nb_time_eat = ft_atoi(argv[5], 0);
		if (game->nb_time_eat <= 0)
			return (1);
	}
	else
		game->nb_time_eat = -1;
	if (game->nb_philo < 2 || game->time_to_die < 0 || game->time_to_eat < 0
		|| game->time_to_sleep < 0 || game->nb_philo > 250)
		return (1);
	if (init_mutex(game))
		return (2);
	init_philo(game);
	return (0);
}
