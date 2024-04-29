/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:05:04 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/29 01:33:03 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

// void	print_info(t_program *program)
// {
// }

void	ft_sleep(int time_to_sleep)
{
	usleep(time_to_sleep * 1000);
}

void	ft_eat(t_program *program, int i)
{
	printf("%llu philo = %d has taken a fork\n", get_time_now(),
		program->philos[i]->number);
	usleep(program->time_to_eat * 1000);
}

void	ft_think(void)
{
	usleep(1000);
}

void	*thread_func(void *tmp)
{
	t_program	*program;

	program = (t_program *)tmp;
	// ft_eat(program);
	// printf("sizeof(t_t_program) = %lu\n", sizeof(t_program));
	printf("%d - %ld\n", program->number_of_philos, pthread_self());
	return (NULL);
}

void	init_philos(t_program *program, t_philo ***philos, int number_of_philos)
{
	int	i;

	i = 0;
	*philos = malloc((number_of_philos + 1) * sizeof(t_philo *));
	while (i < number_of_philos)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		(*philos)[i]->is_die = false;
		(*philos)[i]->number = i + 1;
		pthread_create(&(*philos)[i]->thread, NULL, thread_func,
			(void *)program);
		i++;
	}
}

void	init_program(t_program *program, char *av[], bool is_more_params)
{
	program->number_of_philos = atoi(av[1]);
	program->time_to_die = atoi(av[2]);
	program->time_to_eat = atoi(av[3]);
	program->time_to_sleep = atoi(av[4]);
	program->number_of_time_each_philo_must_eat = -1;
	if (is_more_params)
		program->number_of_time_each_philo_must_eat = atoi(av[5]);
	init_philos(program, &program->philos, program->number_of_philos);
}

void	print_philo_info(t_program *program, bool is_more_param)
{
	int	i;

	is_more_param = is_more_param;
	printf("\nnumber_of_philos = %d\n", program->number_of_philos);
	printf("time_to_die = %d\n", program->time_to_die);
	printf("time_to_eat = %d\n", program->time_to_eat);
	printf("time_to_sleep = %d\n", program->time_to_sleep);
	printf("number_of_time_each_philo_must_eat = %d\n\n",
		program->number_of_time_each_philo_must_eat);
	i = 0;
	while (i < program->number_of_philos - 1)
	{
		printf("number philo = %d\n", program->philos[i]->number);
		if (program->philos[i]->is_die)
			printf("philo is die  = %d\n\n", program->philos[i]->is_die);
		printf("philo is alive = %d\n\n", program->philos[i]->is_die);
		i++;
	}
}

// void	*thread_func(void *tmp)
// {
// 	t_program	*program;

// 	program = (t_program *)tmp;
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		printf("here\n");
// 		printf("\nnumber_of_philos = %d\n", (program)->number_of_philos);
// 		printf("Поток %ld: общая переменная увеличена \n", pthread_self());
// 		printf("тут\n");
// 	}
// 	return (NULL);
// }



void	check_philo_die(t_program *program)
{
	int	i;

	i = 0;
	while (!program->philos[i]->is_die)
	{
		if (program->number_of_philos - 1 == i)
			i = 0;
		i++;
		usleep(50000);
	}
}



int	main(int ac, char *av[])
{
	t_program	*program;
	bool		is_more_params;
	int			i;
	double		start;
	int			j;
	double		end;

	start = get_time_now();
	is_more_params = false;
	program = calloc(sizeof(t_program), 1);
	check_arguments(ac, &is_more_params);
	check_digit(av);
	init_program(program, av, is_more_params);
	check_philo_die(program);
	i = 0;
	while (i < program->number_of_philos - 1)
	{
		// printf("here\n");
		pthread_join((*program).philos[i]->thread, NULL);
		i++;
	}
	// exit(0);
	end = get_time_now();
	printf("%.f\n", end - start);
	// print_philo_info(program, is_more_params);
	// printf("\nnumber_of_philos = %d\n", program->number_of_philos);
	// pthread_create(&thread, NULL, thread_func, (void *)program);
	// pthread_create(&thread2, NULL, thread_func, (void *)program);
	// pthread_join(thread, NULL);
	// pthread_join(thread2, NULL);
	// pthread_mutex_destroy(&mutex);
	// printf("here\n");
	return (0);
}
