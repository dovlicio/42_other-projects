/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:31:46 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/10 14:00:34 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*shift down all elements of stack a by 1*/
void	rra(t_list **stack_a, int print)
{
	t_list	*new_last;
	t_list	*new_first;
	int		size;

	if (!(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) < 2)
		return ;
	new_first = ft_lstlast(*stack_a);
	size = ft_lstsize(*stack_a);
	new_last = *stack_a;
	while (size-- > 2)
		new_last = new_last->next;
	new_last->next = NULL;
	new_first->next = *stack_a;
	*stack_a = new_first;
	if (print)
		ft_printf("rra\n");
}

/*shift down all elements of stack b by 1*/
void	rrb(t_list **stack_b, int print)
{
	t_list	*new_last;
	t_list	*new_first;
	int		size;

	if (!(*stack_b))
		return ;
	if (ft_lstsize(*stack_b) < 2)
		return ;
	new_first = ft_lstlast(*stack_b);
	size = ft_lstsize(*stack_b);
	new_last = *stack_b;
	while (size-- > 2)
		new_last = new_last->next;
	new_last->next = NULL;
	new_first->next = *stack_b;
	*stack_b = new_first;
	if (print)
		ft_printf("rrb\n");
}

/*rra and rrb at the same time*/
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(&(*stack_a), 0);
	rrb(&(*stack_b), 0);
	ft_printf("rrr\n");
}
