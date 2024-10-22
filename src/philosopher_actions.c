/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 01:28:51 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/10 02:56:59 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_info(t_philo *philo, enum e_info type_info)
{
	pthread_mutex_lock(&philo->program->print);
	if (philo->program->is_die)
	{
		pthread_mutex_unlock(&philo->program->print);
		return ;
	}
	if (type_info == FORK)
		printf("%ld %d has taken a fork\n", get_time(philo->program->time)
			- philo->start, philo->number);
	else if (type_info == EAT)
		printf("%ld %d is eating\n", get_time(philo->program->time)
			- philo->start, philo->number);
	else if (type_info == SLEEP)
		printf("%ld %d is sleeping\n", get_time(philo->program->time)
			- philo->start, philo->number);
	else if (type_info == THINK)
		printf("%ld %d is thinking\n", get_time(philo->program->time)
			- philo->start, philo->number);
	else if (type_info == DIE)
	{
		printf("%ld %d is die\n", get_time(philo->program->time) - philo->start,
			philo->number);
		philo->program->is_die = true;
	}
	pthread_mutex_unlock(&philo->program->print);
}

void	ft_sleep(t_philo *philo)
{
	print_info(philo, SLEEP);
	ft_usleep(philo->program->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	print_info(philo, THINK);
	ft_usleep(1);
}

bool	ft_eat(t_philo *philo)
{
	if (check_philo_one(philo))
		return (false);
	take_forks_in_queue(philo);
	if (philo->program->count_eat == -1)
		philo->count_eat = 0;
	print_info(philo, EAT);
	ft_usleep(philo->program->time_to_eat);
	philo->count_eat++;
	if (philo->count_eat >= philo->program->count_eat
		&& philo->program->count_eat != -1)
		philo->finish = true;
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (true);
}

void	*thread_func(void *tmp)
{
	t_philo		*philo;
	long int	time;

	philo = (t_philo *)tmp;
	if (philo->number % 2 == 0)
	{
		print_info(philo, THINK);
		ft_usleep(philo->program->time_to_eat);
	}
	while (1)
	{
		if (!ft_eat(philo))
			philo->program->is_die = true;
		time = get_time(philo->program->time) - philo->end_eat;
		if (check_philo_die(philo, time))
			break ;
		if (philo->finish)
			break ;
		philo->end_eat = get_time(philo->program->time);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
