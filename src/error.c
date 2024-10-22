/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:18:28 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/10 10:55:55 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	print_error_mes(char *mes)
{
	printf(RED "\n  ERROR » " RESET);
	printf("%s\n\n", mes);
	return (false);
}

bool	check_arguments(int ac, bool *is_more_params)
{
	if (ac < 5 || ac > 6)
		return (print_error_mes("A problem with the number of arguments"));
	if (ac == 6)
		*is_more_params = true;
	return (true);
}

bool	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_atoi(av[i]) <= 0)
			return (print_error_mes("Arguments must be greater than 0"));
		if (ft_atoi(av[1]) >= 201)
			return (print_error_mes("Arguments must be less than 200"));
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (print_error_mes("Arguments must be numbers"));
			j++;
		}
		i++;
	}
	return (true);
}
