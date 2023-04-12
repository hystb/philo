/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <nmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:48:54 by nmilan            #+#    #+#             */
/*   Updated: 2023/04/12 17:53:22 by nmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	swap_fork(t_philo *philo)
{
	int	swap;

	if (philo->id % 2)
	{
		swap = philo->left_fork_id;
		philo->left_fork_id = philo->right_fork_id;
		philo->right_fork_id = swap;
	}
	return ;
}
