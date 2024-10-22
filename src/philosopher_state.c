/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:26:26 by mperetia          #+#    #+#             */
/*   Updated: 2024/10/22 22:46:31 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	check_philo_die(t_philo *philo, long int time)
{
	if (time >= philo->program->time_to_die || philo->program->is_die == true)
	{
		print_info(philo, DIE);
		return (true);
	}
	return (false);
}

void	take_forks_in_queue(t_philo *philo)
{		
	if (philo->fork1 < philo->fork2)
	{
		pthread_mutex_lock(philo->fork1);
		print_info(philo, FORK);
		pthread_mutex_lock(philo->fork2);
		print_info(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->fork2);
		print_info(philo, FORK);
		pthread_mutex_lock(philo->fork1);
		print_info(philo, FORK);
	}
}

bool	check_philo_one(t_philo *philo)
{
	if (philo->program->number_of_philos == 1)
	{
		pthread_mutex_lock(philo->fork1);
		print_info(philo, FORK);
		ft_usleep(philo->program->time_to_die);
		print_info(philo, DIE);
		pthread_mutex_unlock(philo->fork1);
		return (true);
	}
	return (false);
}
