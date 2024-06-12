
#include "../push_swap.h"

int correct_format(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
        i++;
    while(str[i])
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return(0);
        }
        i++;
    }
    return(1);
}

void verif_is_int(char **argv)
{
    int i; 

    i = 1;
    while(argv[i])
    {
        if(!correct_format(argv[i]))
        {
            ft_printf("error\n");
            exit(1);   
        }
        i++;
    }
}
int parsing_args(int argc, char **argv,t_args *args)
{
    int i;
    int j;
    long number;

    i = 1;
    j = 0;
    args->params = (int*) malloc(sizeof(int) * (argc));
    if(!args->params)
        return(0);
    while(argv[i])
    {
        number = ft_atol(argv[i]);
        if(number > INT_MAX || number < INT_MIN)
        {
            perror("Number must not exceed INT_MAX or INT_MIN");
            free(args->params);
            exit(1);
        }
        args->params[j] = number;
        j++;
        i++;
    }
    args->params[j] = 0;
    return(0);
}

int is_sorted(int argc, t_args *args)
{
    int i;

    i = 0;
    while(i <= argc)
    {
        if(args->params[i + 1] != '\0'  && args->params[i] > args->params[i + 1])
        {
            return(0);
        }
        i++;
    }
    return(1);
}
