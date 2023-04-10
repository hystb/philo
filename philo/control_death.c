#include "philo.h"

void	lock_philo(t_data *game, int i)
{
	while (i < game->nb_philo)
	{
		pthread_mutex_lock(&game->philo[i].meal_check);
		i++;
	}
	return ;
}

void	unlock_philo(t_data *game, int i)
{
	while (i < game->nb_philo)
	{
		pthread_mutex_unlock(&game->philo[i].meal_check);
		i++;
	}
	return ;
}

int	death_checker(t_philo philo, long time, t_data *game)
{
	long	should_dead;

	should_dead = philo.time_last_eat + game->time_to_die + game->first_time;
	if (should_dead <= time)
	{
		print_philo(philo.id, DIE, game, 1);
		return (1);
	}
	if (game->nb_time_eat != -1 && philo.time_have_eat >= game->nb_time_eat)
	{
		return (1);
	}
	return (0);
}

void	control_death(t_data *game, int i)
{
	while (1)
	{
		make_wait(1);
		lock_philo(game, 0);
		i = 0;
		while (i < game->nb_philo)
		{
			if (death_checker(game->philo[i], get_time(), game))
			{
				unlock_philo(game, 0);
				return ;
			}
			i++;
		}
		unlock_philo(game, 0);
	}
}
