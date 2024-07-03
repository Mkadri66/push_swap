/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:34:24 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 12:45:34 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_current_index(t_stack_node *stack)
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

void	set_target_node(t_stack_node *a, t_stack_node *b)
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
			if (current_a->number > b->number
				&& current_a->number < match_index)
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
	int	len_a; 
	int	len_b; 

	len_a = stack_length(a);
	len_b = stack_length(b);
	while (a)
	{
		a->push_cost = a->index; 
		if (!(a->above_median)) 
			a->push_cost = len_a - (a->index); 
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number 
				&& current_b->number > best_match_index)
			{
				best_match_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_highest(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	set_cheapest(t_stack_node *a)
{
	t_stack_node	*best_match;
	long			best_match_value;

	if (a == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (a)
	{
		if (a->push_cost < best_match_value)
		{
			best_match_value = a->push_cost;
			best_match = a;
		}
		a = a->next;
	}
	best_match->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_a(a, b);
	set_price(a, b);
	set_cheapest(a);
}
