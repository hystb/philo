/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:14:41 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/24 15:01:14 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define SLEEP "is sleeping"
# define INT_MAX 2147483647

typedef struct s_philo
{
	int				id;
	int				time_have_eat;
	int				left_fork_id;
	int				right_fork_id;
	long			time_last_eat;
	int				death;
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
	long			first_time;
	pthread_mutex_t	*forks;
	int				*is_used;
	pthread_mutex_t	*waiting_list;
	pthread_mutex_t	writing;
	t_philo			*philo;
}					t_data;

int		init_mutex(t_data *game);
int		init_philo(t_data *game);
int		init_game(char **argv, t_data *game, int error);
int		ft_isdigit(int c);
long	ft_atoi(const char *str, int i);
void	error_message(int nb_error);
int		ft_putstr_fd(char *str, int fd);
int		game(t_data *game, int i, t_philo *philo);
void	*start_actions(void *philo);
long	get_time(void);
void	print_philo(int id, char *action, t_data *data, int type);
void	make_wait(long time, t_philo *philo);
int		died(t_philo *philo);
void	control_death(t_data *game, int i);
int		error_alloc(t_data *game, int error, int i);
int		error_mutex(t_data *game, int error, int i);
void	swap_fork(t_philo *philo);
void	nxt_step(int **usd, pthread_mutex_t **fork, t_philo *phi, t_data *game);
void	count_eating(t_philo *philo);
void	take_fork(int *used, int *taken, t_philo *phi, t_data *game);
void	give_fork(int **usd, pthread_mutex_t **frk, t_philo *phi, t_data *game);

#endif
