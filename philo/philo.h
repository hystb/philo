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
# define ALLOC_ERROR "Memory allocation failed"
# define THINK "is thinking"
# define EAT "is eating"
# define FORK "has taken a fork"
# define DIE "died"
# define SLEEP " is sleeping"

typedef struct s_philo
{
	int				id;
	int				time_have_eat;
	int				left_fork_id;
	int				right_fork_id;
	long			time_last_eat;
	struct s_data	*game;
	pthread_t		th_id;
	pthread_mutex_t	meal_check;
}						t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_eat;
	int				death;
	long			first_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	died;
	t_philo			*philo;
}					t_data;

int		init_mutex(t_data *game);
int		init_philo(t_data *game);
int		init_game(char **argv, t_data *game, int error);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, int i);
void	error_message(int nb_error);
void	ft_putstr_fd(char *str, int fd);
int		game(t_data *rules);
void	*start_actions(void *philo);
long	get_time(void);
void	print_philo(int id, char *action, t_data *data, int type);
void	make_wait(long time, t_data *game);
int		died(t_data *game);
void	control_death(t_data *game, int i);
int		error_alloc(t_data *game, int error, int i);
int		error_mutex(t_data *game, int error, int i);

#endif