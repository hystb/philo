#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	game_rules;
	int		init;

	if (argc != 6 && argc != 5)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(AMOUNT_ARG_ERROR, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	init = init_game(argv, &game_rules);
	if (init == 1 || init == 2)
	{
		error_message(init);
		return (1);
	}
	/*if (game(&game_rules))
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(THREADS_ERROR, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}*/
	return (0);
}
