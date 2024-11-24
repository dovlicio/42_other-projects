/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:27:48 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/10 14:00:08 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*shift up all elements of stack a by 1*/
void	ra(t_list **stack_a, int print)
{
	t_list	*temp;
	t_list	*last;

	if (!(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	last->next = *stack_a;
	(*stack_a) = temp;
	if (print)
		ft_printf("ra\n");
}

/*shift up all elements of stack b by 1*/
void	rb(t_list **stack_b, int print)
{
	t_list	*temp;
	t_list	*last;

	if (!(*stack_b))
		return ;
	if (ft_lstsize(*stack_b) < 2)
		return ;
	last = ft_lstlast(*stack_b);
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	last->next = *stack_b;
	(*stack_b) = temp;
	if (print)
		ft_printf("rb\n");
}

/*ra and rb at the same time*/
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
