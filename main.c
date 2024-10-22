/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:05:04 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/10 01:41:36 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philosophers.h"

int	main(int ac, char *av[])
{
	t_program	*program;
	bool		is_more_params;
	int			i;

	i = 0;
	is_more_params = false;
	if (!check_arguments(ac, &is_more_params))
		return (0);
	if (!check_digit(av))
		return (0);
	program = ft_calloc(sizeof(t_program), 1);
	init(program, av, is_more_params);
	while (i < program->number_of_philos)
	{
		pthread_join(program->philos[i]->thread, NULL);
		i++;
	}
	free_all(program);
	return (0);
}
