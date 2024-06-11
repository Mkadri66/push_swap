/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:26 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/11 16:58:10 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_args  args;

    if(argc <= 2)
        exit(1);
    verif_is_int(argv);
    parsing_args(argc, argv, &args);
    is_sorted(argc, &args);
    return(0);
}