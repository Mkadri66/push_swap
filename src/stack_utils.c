/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:25:51 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/21 16:33:14 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

int     stack_length(t_stack_node *stack)
{
    int i;

    i = 0;
    if(stack == NULL)
        return (0);
    while(stack != NULL)
    {
        i++;
        stack = stack->next;
    }
    return(i);
}