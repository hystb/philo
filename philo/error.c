#include "philo.h"

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
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}
