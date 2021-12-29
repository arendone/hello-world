#include "push_swap.h"

t_info	*init_push(void)
{
	t_info		*push;

	push = (t_info *)malloc(sizeof(t_info));
    if (push == NULL)
    {
        write(2, "No space left\n", 15);
        return (NULL);
    }
	push->heada = NULL;
	push->headb = NULL;
	push->size_a = 0;
	push->size_b = 0;
    /*char	**input_array;
	int		array_size;
	int		chunk;
	bool	swap;*/
	return (push);
}

t_stack	*addToEmpty(int numb)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
		return (NULL);
	temp->prev = temp;
	temp->num = numb;
	temp->next = temp;
	return (temp);
}

t_stack	**addAtEnd(t_stack **head, int numb) //tengo que checar que se pueda llamar a esta funcion con (&(push->heada))
{
	t_stack	*new;
	t_stack	*ex_new;

	new = addToEmpty(numb);
	if (*head == NULL)
	{
		*head = new;
		return (head);
	}
	else
	{
		ex_new = (*head)->prev;
		new->next = *head;
		new->prev = ex_new;
		ex_new->next = new;
		(*head)->prev = new;
		return (head);
	}
}