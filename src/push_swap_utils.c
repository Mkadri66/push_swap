/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:21:29 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/16 12:17:20 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_double(t_args *args)
{
	int	i;
    int len;
	int j;

	i = 0;
	j = 0;
	len = args->nb_params;
    while (i < len) {
        j = i + 1;
        while (j < len) {
            if (args->params[i] == args->params[j])	
            {
				printf("double \n");    
				return (1);
			}
            j++;
        }
        i++;
    }
	return (0);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

void	display_error(char *str)
{
	ft_printf(str);
	exit(1);
}

char	**verif_split(char *argv)
{
	char	**args_split;
	int		len;

	args_split = ft_split(argv, ' ');
	if (!args_split)
		return (0);
	len = array_len(args_split);
	if (!verif_is_int(args_split))
	{
		free_array(args_split);
		display_error("error\n");
	}
	if (len == 1)
	{
		free_array(args_split);
		exit(1);
	}
	return (args_split);
}
