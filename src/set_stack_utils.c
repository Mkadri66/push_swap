/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:34:24 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/25 23:20:35 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	set_curent_index(t_stack_node *stack)
{
	int	i;
	int	center;
	
	i = 0;
	if (stack == NULL)
		return ;
	center = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= center)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			match_index;
	
	while (b)
	{
		match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number && current_a->number < match_index)
			{
				match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == LONG_MAX)
			b->target_node = smallest_in_stack(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
static void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	a_length;
	int	b_length;
	
	a_length = stack_length(a);
	b_length = stack_length(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = b_length - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += a_length - (b->target_node->index);
		b = b->next;
	}
}
static void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*best_match;
	long			best_match_value;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match = b;
		}
		b = b->next;
	}
	best_match->cheapest = true;
}
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_curent_index(a);
	set_curent_index(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}