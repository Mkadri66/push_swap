/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:22:23 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 12:45:49 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_double(t_stack_node *a, int number)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->number == number)
			return (1);
		a = a->next;
	}
	return (0);
}

bool	is_sorted(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->number > a->next->number)
			return (false);
		a = a->next;
	}
	return (true);
}

void	display_error(char *str)
{
	ft_printf(str);
	exit(1);
}
