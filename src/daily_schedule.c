/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily_schedule.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:36:19 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/07 20:42:23 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_info(t_philo *philo, enum e_info type_info)
{
	pthread_mutex_lock(&philo->program->print);
	if (type_info == FORK)
		printf("%llu %d has taken a fork\n", get_time_now() - philo->start,
			philo->number);
	else if (type_info == EAT)
		printf("%llu %d is eating\n", get_time_now() - philo->start,
			philo->number);
	else if (type_info == SLEEP)
		printf("%llu %d is sleeping\n", get_time_now() - philo->start,
			philo->number);
	else if (type_info == THINK)
		printf("%llu %d is thinking\n", get_time_now() - philo->start,
			philo->number);
	else if (type_info == DIE)
		printf("%llu %d is die\n", get_time_now() - philo->start,
			philo->number);
	pthread_mutex_unlock(&philo->program->print);
}

void	ft_sleep(t_philo *philo)
{
	print_info(philo, SLEEP);
	usleep(philo->program->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	print_info(philo, THINK);
	usleep(1000);
}

void	ft_eat(t_philo *philo)
{
	// int result = pthread_mutex_lock(philo->fork1);
	// if (result != 0) {
	//     // Обработка ошибки блокировки мьютекса fork1
	//     // Например,
	// вы можете вывести сообщение об ошибке и завершить выполнение потока
	// .
	// }
	// print_info(philo, FORK);
	// result = pthread_mutex_trylock(philo->fork2);
	// if (result != 0) {
	//     // Обработка ошибки блокировки мьютекса fork2
	//     // Например,
	// вы можете вывести сообщение об ошибке и освободить мьютекс fork1.
	//     pthread_mutex_unlock(philo->fork1);
	//     return ;
	// }
	// print_info(philo, FORK);
	// philo->start_eat = get_time_now();
	// if (philo->program->count_eat == -1)
	//     philo->count_eat = 0;
	// print_info(philo, EAT);
	// usleep(philo->program->time_to_eat * 1000);
	// philo->count_eat++;
	// if (philo->count_eat >= philo->program->count_eat)
	//     philo->finish = true;
	// pthread_mutex_unlock(philo->fork1);
	// pthread_mutex_unlock(philo->fork2);
	pthread_mutex_lock(philo->fork1);
	print_info(philo, FORK);
	pthread_mutex_lock(philo->fork2);
	print_info(philo, FORK);
	philo->start_eat = get_time_now();
	if (philo->program->count_eat == -1)
		philo->count_eat = 0;
	print_info(philo, EAT);
	usleep(philo->program->time_to_eat * 1000);
	philo->count_eat++;
	if (philo->count_eat >= philo->program->count_eat)
		philo->finish = true;
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}
// print_info(philo, SLEEP);
// print_info(philo, THINK);

void	*thread_func(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if (philo->number % 2 == 0)
	{
		// print_info(philo, THINK);
		usleep(philo->program->time_to_eat * 1000);
	}
	while (philo->is_die == false)
	{
		ft_eat(philo);
		if (philo->is_die)
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
