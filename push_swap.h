/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:02:07 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/17 15:06:46 by mkadri           ###   ########.fr       */
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
	int	*params;
	int	nb_params;
}	t_args;

int		parsing_args(int argc, char **argv, t_args *args);
int		verif_is_int(char **argv);
int		is_sorted(t_args *args);
int		is_sign(char c);
int		check_double(t_args *args);
int		array_len(char **array);
int		split_args(char *argv, t_args *args);
void	free_array(char **array);
void	display_error(char *str);
void	check_input(t_args *args);
long	ft_atol(const char *str);
char	**verif_split(char *argv, t_args *args);

#endif