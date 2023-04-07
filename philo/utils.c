#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str, int i)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		if (res != ((res * 10 + (sign * (str[i] - '0'))) / 10))
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		res = res * 10 + sign * (str[i++] - '0');
	}
	return (res);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_philo(int id, char *action, t_data *game, int type)
{
	if (died(game) || type == 1)
	{
		pthread_mutex_lock(&game->writing);
		printf("%ld", get_time() - game->first_time);
		printf(" %d %s\n", id + 1, action);
		pthread_mutex_unlock(&game->writing);
	}
}

void	make_wait(long time, t_data *game)
{
	long	actual;

	actual = get_time();
	while (died(game))
	{
		if (get_time() - actual >= time)
			break ;
		usleep(50);
	}
}
