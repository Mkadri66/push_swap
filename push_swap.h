/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:02:07 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/12 16:59:37 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <limits.h>

typedef struct s_args
{
    int *params;
}   t_args;

int     parsing_args(int argc, char **argv, t_args *args);
void    verif_is_int(char **argv);
int     is_sorted(int argc, t_args *args);
int     is_sign(char c);
long	ft_atol(const char *str);
// void    free_struct(t_args *args);

#endif