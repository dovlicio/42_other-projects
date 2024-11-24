/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_from_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:28:09 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/19 15:27:36 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_b_big(t_moves *move, t_list **stack_a)
{
	if (ft_lstsize(*stack_a) / 2 >= get_index(stack_a, get_min(stack_a)))
		move->ra += get_index(stack_a, get_min(stack_a));
	else
		move->rra += ft_lstsize(*stack_a) - \
			get_index(stack_a, get_min(stack_a));
	move->pa += 1;
}

static void	execute_b_small(t_moves *move, t_list **stack_a)
{
	if (ft_lstsize(*stack_a) / 2 >= get_index(stack_a, get_min(stack_a)))
		move->ra += get_index(stack_a, get_min(stack_a));
	else
		move->rra += ft_lstsize(*stack_a) - \
			get_index(stack_a, get_min(stack_a));
	move->pa += 1;
}

static void	execute_b_mid(t_moves *move, t_list **stack_a, int n)
{
	if (ft_lstsize(*stack_a) / 2 > get_index(stack_a, n))
		move->ra += get_index(stack_a, n) + 1;
	else
		move->rra += ft_lstsize(*stack_a) - get_index(stack_a, n) - 1;
	move->pa += 1;
}

void	execute_from_b(t_list **stack_a, t_list **stack_b, t_list *current)
{
	t_moves	move;
	int		next;

	ft_memset(&move, 0, sizeof(t_moves));
	if (*(int *)current->content < get_min(stack_a))
		execute_b_small(&move, stack_a);
	else if (*(int *)current->content > get_max(stack_a))
		execute_b_big(&move, stack_a);
	else
	{
		next = get_next_smaller(stack_a, current->content);
		execute_b_mid(&move, stack_a, next);
	}
	while ((move.ra)-- > 0)
		ra(stack_a, 1);
	while ((move.rra)-- > 0)
		rra(stack_a, 1);
	while ((move.pa)--)
	{
		pa(stack_a, stack_b);
		// ft_printf("STACK A: ");
		// print_stack(stack_a);
		// ft_printf("STACK B: ");
		// print_stack(stack_b);
	}
}
