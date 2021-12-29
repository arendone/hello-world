#include "push_swap.h"

/*
** Check if the string sent as arguments is invalid:
** "-5-", "--4", "+6+", just NULL, only spaces or tabs, other symbols than '-'
** or '+' or numbers, and that there are no duplications.
** Check for the maximal  integer is performed in atoi. If there are no errors,
** all the numbers are saved in the stack_a in the structure t_push.
** @nu - is where the final numbers as strings are saved.
*/

int	long_atoi(char *str, char **nums, t_info *push)
{
	long long int	n;
	bool				sign;
	size_int		i;

	n = 0;
	sign = 1;
    i = 0;
	if (str[i] == '-')
		sign = -1;
	else if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
        if (sign * n > INT_MAX || sign * n < INT_MIN)
			error_exit(nums, push);
	}
	return ((int)sign * n);
}

int	check_rep(t_info *push, int numb)
{
	t_stack	*tem;
    t_stack *head;

    head = push->heada;
	if (head != NULL)
	{
		if ((head->num) == numb)
			return (1);
		else
		{
			tem = head->next;
			while (tem != head)
			{
				if ((tem->num) == numb)
					return (1);
				tem = tem->next;
			}
		}
	}
	return (0);
}

int	invalid_argv(char *argv, t_info *push)
{
	char		**nu;
	size_t		i;
	size_t		j;

	i = 0;
	nu = ft_strsplit(argv, ' '); //FALTAAA REVISAR EN LIBFT NUEVA Y NORMINATTE
	if (nu[i] == NULL)
	{
		ft_freearray(nu);
		return (-1);
	}
	while (nu[i])
	{
		j = 0;
		while (nu[i][j])
        {
            if (!((nu[i][j] >= '0' && nu[i][j] <= '9') ||
				(nu[i][j] == '-' && j == 0 && nu[i][j + 1]) ||
				(nu[i][j] == '+' && j == 0 && nu[i][j + 1])))
				error_exit(nu, push);
            j++;
        }
        checkandadd(t_info *push, nu, i);
        i++;
	}
	ft_freearray(nu);
	return (0); //tengo 27 lineas, mi idea es agregar una funcion con ft_freearray y valor de return, otra idea es definir a i y/o j en la funcion previa a esta ;)
}

checkandadd(t_info *push, char **nu, size_t i)
{
    int numb;
    t_stack       *head;

    head = push->heada;
    numb = atoi_push_swap(nu[i]);
    if (check_rep(t_info *push, int numb) == 1)
        error_exit(nu, push);
    addAtEnd(&head, (int)numb);
	push->size_a++; //hay que inizializar al push
}
