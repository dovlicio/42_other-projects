/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:26:05 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/10 14:01:28 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*swap first two elements at the top of stack a*/
void	sa(t_list *stack, int print)
{
	int	*temp_content;

	if (!stack)
		return ;
	if (ft_lstsize(stack) < 2)
		return ;
	temp_content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp_content;
	if (print)
		ft_printf("sa\n");
}

/*swap first two elements at the top of stack b*/
void	sb(t_list *stack, int print)
{
	int	*temp_content;

	if (!stack)
		return ;
	if (ft_lstsize(stack) < 2)
		return ;
	temp_content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp_content;
	if (print)
		ft_printf("sb\n");
}

/*sa and sb at the same time*/
void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
