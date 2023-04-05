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