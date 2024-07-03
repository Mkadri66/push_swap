/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:39:04 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 19:47:26 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_b(a, b);
}

void	move_node_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	conclude_rotation(a, cheapest_node, 'a');
	conclude_rotation(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	move_node_to_a(t_stack_node **a, t_stack_node **b)
{
	conclude_rotation(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
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

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
				&& current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = smallest_in_stack(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
