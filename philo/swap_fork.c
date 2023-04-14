/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:48:54 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/14 11:31:56 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	swap_fork(t_philo *philo)
{
	int	swap;

	/*if (philo->game->nb_philo % 2 == 1)
		return ;*/
	if (philo->id % 2)
	{
		swap = philo->left_fork_id;
		philo->left_fork_id = philo->right_fork_id;
		philo->right_fork_id = swap;
	}
	return ;
}
