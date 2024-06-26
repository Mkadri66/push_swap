/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:56:28 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/26 17:46:44 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, false);
	set_curent_index(*a);
	set_curent_index(*b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_length(*a) > 3)
	{
		init_nodes(*a, *b);
		conclude_rotation(a, smallest_in_stack(*a), 'a');
		pb(b, a, false);
	}
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
	t_stack_node	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(a, b, cheapest);
	conclude_rotation(b, cheapest, 'b');
	conclude_rotation(a, cheapest->target_node, 'a');
	pa(a, b, false);
}

void	master_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				a_lenght;

	a_lenght = stack_length(*a);
	if (a_lenght == 5)
		sort_five(a, b);
	else
	{
		while (a_lenght-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_node_to_a(a, b);
	}
	set_curent_index(*a);
	smallest = smallest_in_stack(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
