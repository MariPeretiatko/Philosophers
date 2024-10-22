/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:18:29 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/10 01:41:40 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	free_philo(t_philo **philos, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		free(philos[i]);
		i++;
	}
}

void	free_mutex(t_program *program)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->print);
	while (i < program->number_of_philos)
	{
		pthread_mutex_destroy(&program->fork[i]);
		i++;
	}
}

void	free_all(t_program *program)
{
	free_philo(program->philos, program->number_of_philos);
	free(program->philos);
	free_mutex(program);
	free(program->fork);
	free(program);
}
