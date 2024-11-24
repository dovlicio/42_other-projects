/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:27:28 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/10 13:56:20 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*take the first element of the top of a and put it on top of b*/
void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
	ft_printf("pb\n");
}

/*take the first element of the top of b and put it on top of a*/
void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = temp;
	ft_printf("pa\n");
}
