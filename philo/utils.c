/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:14:14 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/24 13:39:11 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(const char *str, int i)
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
	if (type == 1)
	{
		pthread_mutex_lock(&game->writing);
		printf("%ld %d %s\n", get_time() - game->first_time, id + 1, action);
		pthread_mutex_unlock(&game->writing);
	}
	else if (died(&game->philo[id]))
	{
		pthread_mutex_lock(&game->writing);
		printf("%ld %d %s\n", get_time() - game->first_time, id + 1, action);
		pthread_mutex_unlock(&game->writing);
		if (type == 2)
			make_wait(game->time_to_sleep, &game->philo[id]);
	}
}

void	make_wait(long time, t_philo *philo)
{
	long	actual;
	long	wait;
	int		first;

	first = 0;
	if (time < 2000)
		wait = time * 0.9;
	else
		wait = 1900;
	actual = get_time();
	if (time <= 0)
		return ;
	while (died(philo))
	{
		if (get_time() - actual > time)
			return ;
		if (first == 0)
		{
			usleep(wait);
			first = 1;
		}
		else
			usleep(100);
	}
}
