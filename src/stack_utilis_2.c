/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:33:29 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/26 17:47:12 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack_node	*smallest_in_stack(t_stack_node *stack)
{
	t_stack_node	*smallest_node;
	long			smallest;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->number < smallest)
		{
			smallest = stack->number;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (stack == NULL)
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
	return (highest_node);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, false);
	set_curent_index(*a);
	set_curent_index(*b);
}
