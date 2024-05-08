/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:18:29 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/07 20:33:31 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	free_philo(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < philos[0]->program->number_of_philos)
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
	free_philo(program->philos);
	free(program->philos);
	free_mutex(program);
	free(program->fork);
	free(program);
}

void	join_all_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_join((*program).philos[i]->thread, NULL);
		i++;
	}
}
