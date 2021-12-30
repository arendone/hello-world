#include "push_swap.h"

void    normalization(t_info *push)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = push->heada;
    while (i < (push->size_a))
    {
        if ((tmp->flag == 0) && ismin_stacka(push, tmp->num, 1))
        {
            tmp->num = i;
            tmp->flag = 1;
            i++;
        }
        tmp = tmp->next;
    }
}


bool    ismin_stacka(t_info *push, int min, int init)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = push->heada;
    while (i < (push->size_a))
    {
        if (init && (min > (tmp->num)) && (tmp->flag == 0))
            return (false);
        if (!init && (min > (tmp->num)))
            return (false);
        tmp = tmp->next;
        i++;
    }
    return (true);
}

int	algorithm_b_shortesway2rotate(t_info *push, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = push->headb;
	i = 0;
	while (i < push->size_b)
	{
		if (tmp->num == num)
		{
			return (i > (push->size_b / 2));
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int	algorithm_a_shortesway2rotate(t_info *push, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = push->heada;
	i = 0;
	while (i < push->size_a)
	{
		if (tmp->num == num)
		{
			return (i > (push->size_a / 2));
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	algorithm_putnumbertop(t_info *push, int nbr)
{
	int	dir;

	dir = algorithm_b_shortesway2rotate(push, nbr);
	while (push->headb->num != nbr)
	{
		if (push->headb->num == (nbr - 1) && push->swap == false)
		{
			pa(push);
			push->swap = true;
		}			
		else if (dir == 1)
			rrb(push);
		else
			rb(push);
	}	
}