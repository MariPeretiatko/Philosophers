/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:05:04 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/07 21:22:55 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

bool	check_count_eat_all(t_philo **philos)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < philos[0]->program->number_of_philos)
	{
		if (philos[i]->finish == true)
			count++;
		i++;
	}
	if (count >= philos[0]->program->number_of_philos)
		return (true);
	return (false);
}

// && philo->count_eat == philo->program->count_eat))
bool	finish_program(t_philo *philo, long int time)
{
	// long int	time;
	// time = get_time_now() - philo->start_eat;
	if (time >= philo->program->time_to_die || (philo->program->count_eat > 0
			&& check_count_eat_all(philo->program->philos)))
	{
		if (time >= philo->program->time_to_die)
			print_info(philo, DIE);
		philo->is_die = true;
		// printf("change state of philo\n");
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		pthread_mutex_lock(&philo->program->print);
		return (true);
		// return (true);
	}
	return (false);
}

bool	check_philo_die(t_program *program)
{
	int			i;
	long int	time;

	i = 0;
	while (program->philos[i]->is_die == false)
	{
		time = get_time_now() - program->philos[i]->start_eat;
		if (program->number_of_philos - 1 == i)
			i = 0;
		else
			i++;
		if (finish_program(program->philos[i], time))
			return (true);
		// if (finish_program(program->philos[i]))
		// printf("here\n");
		// usleep(1000);
	}
	return (true);
}

int	main(int ac, char *av[])
{
	t_program	*program;
	bool		is_more_params;

	is_more_params = false;
	program = ft_calloc(sizeof(t_program), 1);
	check_arguments(ac, &is_more_params);
	check_digit(av);
	init(program, av, is_more_params);
	if (check_philo_die(program))
	{
		printf("sdfjdb here\n");
		// join_all_threads(program);
		free_all(program);
		// exit(1);
	}
	// join_all_threads(program);
	// free_all(program);
	return (0);
}
