/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:26 by mkadri            #+#    #+#             */
/*   Updated: 2024/06/16 12:20:34 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_args  args;

    if(argc <= 1)
        exit(1);
    else if (argc == 2)
        split_args(argv[1], &args);
    else if (argc > 2)
        parsing_args(argc, argv, &args);
    if(!is_sorted(&args) || !check_double(&args))
    {
        printf("ok\n");
        free(args.params);
        exit(1);
    } 
    else 
    {
        display_error("error\n");
        free(args.params);
    }
    return(0);
}
