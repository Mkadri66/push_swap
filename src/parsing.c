/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:21:23 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 19:46:13 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	correct_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	verif_is_int(char *argv)
{
	if (!correct_format(argv))
		return (0);
	return (1);
}

void	stack_init(t_stack_node **a, char **argv, bool flag)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!verif_is_int(argv[i]))
			error_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag);
		if (check_double(*a, (int)nbr))
			error_free(a, argv, flag);
		create_node(a, (int)nbr);
		++i;
	}
	if (flag)
		free_matrix(argv);
}
