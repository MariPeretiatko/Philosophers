/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:12:13 by mperetia          #+#    #+#             */
/*   Updated: 2024/04/29 01:24:13 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

void	print_error_mes(char *mes)
{
	printf("%s\n", mes);
	exit(1);
}

unsigned long long	get_time_now(void)
{
	struct timeval		tv;
	unsigned long long	time_millisecond;

	gettimeofday(&tv, NULL);
	time_millisecond = tv.tv_sec * 1000;
	time_millisecond += tv.tv_usec / 1000;
	return (time_millisecond);
}

void	check_arguments(int ac, bool *is_more_params)
{
	if (ac < 5 || ac > 6)
	{
		printf("%d\n", ac);
		print_error_mes("Problem with arguments");
	}
	else
	{
		if (ac == 6)
			*is_more_params = true;
	}
}

void	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if(!is_digit(av[i][j]))
				print_error_mes("Prarams need only digits");
			j++;
		}
		i++;
	}
}