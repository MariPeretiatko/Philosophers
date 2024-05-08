/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:18:28 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/07 21:09:34 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	print_error_mes(char *mes)
{
	printf(RED"\n  ERROR » "RESET);
	printf("%s\n\n", mes);
	exit(1);
}

void	check_arguments(int ac, bool *is_more_params)
{
	if (ac < 5 || ac > 6)
		print_error_mes("A problem with the number of arguments");
	if (ac == 6)
		*is_more_params = true;
}

void	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_atoi(av[i]) <= 0)
			print_error_mes("Arguments must be greater than 0");
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				print_error_mes("Arguments must be numbers");
			j++;
		}
		i++;
	}
}
