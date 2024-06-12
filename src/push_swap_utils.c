
#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;
    int     i;

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