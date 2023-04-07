#include "philo.h"

int	error_alloc(t_data *game, int error, int i)
{
	if (error == 1)
		return (3);
	if (error == 2)
	{
		free(game->forks);
		return (2);
	}
	if (error == 3 || error == 4)
		return (error_mutex(game, error, 0));
	if (error == 5 || error == 6)
	{
		while (i < game->nb_philo)
			pthread_mutex_destroy(&game->forks[i++]);
		free(game->forks);
		pthread_mutex_destroy(&game->writing);
		pthread_mutex_destroy(&game->died);
		if (error == 5)
			return (3);
		free (game->philo);
		return (2);
	}
	return (0);
}

int	error_mutex(t_data *game, int error, int i)
{
	while (i < game->nb_philo)
		pthread_mutex_destroy(&game->forks[i++]);
	free(game->forks);
	if (error == 4)
		pthread_mutex_destroy(&game->writing);
	return (1);
}

void	error_message(int nb_error)
{
	if (nb_error == 2)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(MUTEX_ERROR, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (nb_error == 1)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(ARG_ERROR, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (nb_error == 3)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(ALLOC_ERROR, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}
