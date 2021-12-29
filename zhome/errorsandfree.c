#include "push_swap.h"

void	error_exit(char **nums, t_info *push)
{
	ft_putendl_fd("Error", 2);
	ft_freearray(nums);
	free_push(push);
	exit(1);
}

void	free_stack(t_stack *head)
{
	t_stack	*temp_node;
    t_stack *prev;

	if (head == NULL)
		return ;
	prev = (head->prev);
	prev->next = NULL;
	while (head->next)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
	free(head);
	head = NULL;
}

void	free_push(t_push *push)
{
	free_stack(push->heada);
	free_stack(push->headb);
	free(push);
    push = NULL;
}