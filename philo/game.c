#include "philo.h"

void	*start_actions(void *philo)
{
	t_philo	*phi;

	phi = philo;
	printf("I AM PHILO %d\n", phi->id);

	return (NULL);
}

int	game(t_data *rules)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = rules->philo;
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, start_actions, &philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}

	return (0);
}
