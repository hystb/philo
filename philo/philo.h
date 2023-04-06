#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

# define ARG_ERROR "Arguments wrongly sets"
# define MUTEX_ERROR "Mutex not correctly initatized"
# define AMOUNT_ARG_ERROR "Program take only 4 or 5 arguments"
# define THREADS_ERROR "Error during thread creation"

typedef struct s_philo
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			time_last_eat;
	struct s_data		*game;
	pthread_t			thread_id;
}						t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	writing;
	int				died;
	t_philo			philo[250];
}					t_data;

int		init_mutex(t_data *game);
void	init_philo(t_data *game);
int		init_game(char **argv, t_data *game);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, int i);
void	error_message(int nb_error);
void	ft_putstr_fd(char *str, int fd);
int		game(t_data *rules);
void	*start_actions(void *philo);

#endif