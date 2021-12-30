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