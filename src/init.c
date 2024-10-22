/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:11:00 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/10 03:09:37 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	init_program(t_program *program, char *av[], bool is_more_params)
{
	program->is_die = false;
	program->number_of_philos = ft_atoi(av[1]);
	program->time_to_die = ft_atoi(av[2]);
	program->time_to_eat = atoi(av[3]);
	program->time_to_sleep = atoi(av[4]);
	program->count_eat = -1;
	if (is_more_params)
		program->count_eat = atoi(av[5]);
	pthread_mutex_init(&program->print, NULL);
	program->fork = malloc(sizeof(pthread_mutex_t) * program->number_of_philos);
	if (!program->fork)
		print_error_mes("Memory allocation problems(fork)");
	gettimeofday(&program->time, NULL);
}
// init_mutex(program);

void	init_treads(t_philo ***philos, int number_of_philos)
{
	int	i;

	i = 0;
	while (i < number_of_philos)
	{
		(*philos)[i]->start = get_time((*philos)[i]->program->time);
		(*philos)[i]->end_eat = get_time((*philos)[i]->program->time);
		pthread_create(&(*philos)[i]->thread, NULL, thread_func, (*philos)[i]);
		i++;
	}
}

void	init_mutex(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_mutex_init(&program->fork[i], NULL);
		i++;
	}
}

void	init_philos(t_program *program, int number_of_philos)
{
	int	i;

	i = 0;
	program->philos = malloc(sizeof(t_philo *) * number_of_philos);
	if (!program->philos)
		print_error_mes("Memory allocation problems(philos)");
	while (i < number_of_philos)
	{
		program->philos[i] = malloc(sizeof(t_philo));
		program->philos[i]->count_eat = 0;
		program->philos[i]->finish = false;
		program->philos[i]->number = i + 1;
		program->philos[i]->program = program;
		program->philos[i]->fork1 = &program->fork[i];
		if (i == number_of_philos - 1)
			program->philos[i]->fork2 = &program->fork[0];
		else
			program->philos[i]->fork2 = &program->fork[i + 1];
		i++;
	}
}

void	init(t_program *program, char *av[], bool is_more_params)
{
	init_program(program, av, is_more_params);
	init_philos(program, program->number_of_philos);
	init_mutex(program);
	init_treads(&program->philos, program->number_of_philos);
}
