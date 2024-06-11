
#include "../push_swap.h"

void verif_is_int(char **argv)
{
    int i; 

    i = 1;
    while(argv[i])
    {
        if(ft_atoi(argv[i]) == 0)
        {
            perror("error non numeric character");
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

int is_sorted(t_args *args)
{
    int i;

    i = 0;
    while(args->params[i])
    {
        printf("%d \n", args->params[i]);
        if((args->params[i] != '\0' && args->params[i + 1] != '\0' ) && (args->params[i] > args->params[i + 1]))
        {
            free(args->params);
            exit(1);
        }
        i++;
    }
    return(1);
}
