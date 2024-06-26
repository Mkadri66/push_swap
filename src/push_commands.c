/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:33:00 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/26 17:39:05 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*dest_node;

	if (*src == NULL)
		return ;
	dest_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	dest_node->previous = NULL;
	if (*dest == NULL)
	{
		*dest = dest_node;
		dest_node->next = NULL;
	}
	else
	{
		dest_node->next = *dest;
		dest_node->next->previous = dest_node;
		*dest = dest_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}

void	conclude_rotation(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
