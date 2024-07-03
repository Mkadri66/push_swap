/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:56:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/03 12:47:52 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, false);
	set_current_index(*a);
	set_current_index(*b);
}

void	sort_three(t_stack_node **a)
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

void	move_node_to_a(t_stack_node **a, t_stack_node **b)
{
	conclude_rotation(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	move_node_to_b(t_stack_node **a, t_stack_node **b)
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
static void	set_target_b(t_stack_node *a, t_stack_node *b)
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
void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_b(a, b);
}
static void	min_on_top(t_stack_node **a)
{
	while ((*a)->number != smallest_in_stack(*a)->number)
	{
		if (smallest_in_stack(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
void	master_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a; 

	len_a = stack_length(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_sorted(*a)) 
	{
		init_nodes_a(*a, *b);
		move_node_to_b(a, b);
	}
	sort_three(a);
	while (*b) 
	{
		init_nodes_b(*a, *b);
		move_node_to_a(a, b); 
	}
	set_current_index(*a);
	min_on_top(a);
}
