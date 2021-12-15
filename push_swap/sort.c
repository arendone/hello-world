
#include "push_swap.h"
#include <stdio.h> //BORRALOOOOOOOOOO

void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
    t_stack *next_stacka;
    t_stack *last_stacka;

    next_stacka = (*pointer_heada)->next;
    last_stacka = (*pointer_heada)->prev;

    /while ((*pointer_heada)->number != 9) 
    {
        rra(pointer_heada); //algoritmo deberia decidir si rra o ra
    }
    pb(pointer_heada, pointer_headb);
    while (((*pointer_heada)->number) < ((*pointer_headb)->number)) 
    {
        pb(pointer_heada, pointer_headb);
        next_stacka = (*pointer_heada)->next;
        last_stacka = (*pointer_heada)->prev;
    }
}

/*void	sort(t_stack **pointer_heada, t_stack **pointer_headb)
{
    t_stack *last_stacka;
    //t_stack *first_stackb;

    rra(pointer_heada);
    pb(pointer_heada, pointer_headb);

    last_stacka = (*pointer_heada)->prev;

    while ((((*pointer_heada)->number) != (last_stacka->number)) && (last_stacka->number > (*pointer_headb)->number))
    {
        rra(pointer_heada);
        pb(pointer_heada, pointer_headb);
        last_stacka = (*pointer_heada)->prev;
    }
    printf("LAST: %d \n", last_stacka->number);
    while ((*pointer_headb != NULL) && ((*pointer_headb)->number) > (last_stacka->number))
    {
        pa(pointer_heada, pointer_headb);
    }
    rra(pointer_heada);
    pb(pointer_heada, pointer_headb);
}*/