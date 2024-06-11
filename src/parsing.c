
#include "../push_swap.h"

int is_sign(char c)
{
    if(c == 45)
        return(1);
    return(0);
}

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
            ft_printf("error");
            exit(1);   
        }
        i++;
    }
}
void parsing_args(int argc, char **argv,t_args *args)
{
    int i;
    int j;

    i = 1;
    j = 0;
    args->params = (int*) malloc(sizeof(int) * (argc));
    while(argv[i])
    {
        args->params[j] = ft_atoi(argv[i]);
        j++;
        i++;
    }
    args->params[j] = 0;
}

int is_sorted(int argc, t_args *args)
{
    int i;

    i = 1;
    while(i <= argc)
    {
        if(args->params[i + 1] != '\0'  && args->params[i] > args->params[i + 1])
        {
            ft_printf("Not sorted");
            free(args->params);
            exit(1);
        }
        i++;
    }
    return(1);
}
