/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:56:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/24 19:09:29 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int			highest;
	t_stack_node	*highest_node;
	
	if(stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->number > highest)
		{
			highest = stack->number;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return(highest_node);
}

void sort_three(t_stack_node **a)
{
	t_stack_node	*highest;
	
	highest = find_highest(*a);
	if (*a == highest)
		ra(a, false);
	else if ((*a)->next == highest)
		rra(a, false);
	if ((*a)->number > (*a)->next->number)
		sa(a, false);
}