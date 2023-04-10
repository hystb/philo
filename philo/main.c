#include "philo.h"

static void	clear_data(t_data game, int i)
{
	while (i < game.nb_philo)
	{
		pthread_mutex_destroy(&game.philo[i].meal_check);
		pthread_mutex_destroy(&game.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&game.writing);
	free(game.philo);
	free(game.forks);
}

static void	print_fd(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
}

int	main(int argc, char **argv)
{
	t_data	game_rules;
	int		init;

	if (argc != 6 && argc != 5)
	{
		print_fd("Error: ", AMOUNT_ARG_ERROR, "\n");
		return (1);
	}
	init = init_game(argv, &game_rules, 0);
	if (init)
	{
		error_message(init);
		return (1);
	}
	if (game(&game_rules, 0, NULL))
	{
		print_fd("Error: ", THREADS_ERROR, "\n");
		clear_data(game_rules, 0);
		return (1);
	}
	clear_data(game_rules, 0);
	return (0);
}
