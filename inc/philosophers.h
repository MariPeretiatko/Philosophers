/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:16:22 by mperetia          #+#    #+#             */
/*   Updated: 2024/05/07 21:06:25 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define END "\033[0m"
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define WHITE "\033[1;37m"
# define BYELLOW "[\033[1;33m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"

enum						e_info
{
	FORK = 0,
	EAT,
	SLEEP,
	THINK,
	DIE
};

typedef struct s_program	t_program;

typedef struct s_philo
{
	bool					is_die;
	int						number;
	pthread_t				thread;
	pthread_mutex_t			*fork1;
	pthread_mutex_t			*fork2;
	int						count_eat;
	bool					finish;
	long int				start;
	long int				start_eat;
	t_program				*program;

}							t_philo;

typedef struct s_program
{
	int						number_of_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						count_eat;
	t_philo					**philos;
	pthread_mutex_t			print;
	pthread_mutex_t			*fork;
}							t_program;

int							ft_atoi(const char *str);
void						*ft_calloc(size_t count, size_t size);
bool						is_digit(int c);
bool						print_error_mes(char *mes);
unsigned long long			get_time_now(void);
void						check_arguments(int ac, bool *is_more_params);
void						check_digit(char **av);

void						init(t_program *program, char *av[],
								bool is_more_params);
void						*thread_func(void *tmp);

void						print_info(t_philo *philo, enum e_info type_info);

void						join_all_threads(t_program *program);
void						free_all(t_program *program);

#endif