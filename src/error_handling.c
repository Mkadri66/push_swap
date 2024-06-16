/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:22:23 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/16 18:22:54 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_double(t_args *args)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	len = args->nb_params;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (args->params[i] == args->params[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nb_params)
	{
		if (args->params[i + 1] && (args->params[i] > args->params[i + 1]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	display_error(char *str)
{
	ft_printf(str);
	exit(1);
}

void	check_input(t_args *args)
{
	if (is_sorted(args))
	{
		free(args->params);
		display_error("sorted\n");
		exit(1);
	}
	else if (check_double(args))
	{
		free(args->params);
		display_error("double\n");
		exit(1);
	}
	(void) args;
}
