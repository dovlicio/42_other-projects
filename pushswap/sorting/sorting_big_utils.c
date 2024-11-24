/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:34:02 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/13 17:43:01 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list **stack)
{
	int		*content_int;
	t_list	*temp;

	if (*stack)
	{
		temp = *stack;
		while (temp)
		{
			content_int = temp->content;
			ft_printf("%d ", *content_int);
			temp = temp->next;
		}
	}
	ft_printf("\n");
}

int	get_min(t_list **stack)
{
	int		*min;
	t_list	*t;

	min = (*stack)->content;
	t = (*stack)->next;
	while (t)
	{
		if (*min > *(int *)t->content)
			min = t->content;
		t = t->next;
	}
	return (*min);
}

int	get_max(t_list **stack)
{
	int		*max;
	t_list	*t;

	max = (*stack)->content;
	t = (*stack)->next;
	while (t)
	{
		if (*max < *(int *)t->content)
			max = t->content;
		t = t->next;
	}
	return (*max);
}

int	get_index(t_list **stack, int current)
{
	int		i;
	t_list	*t;

	i = 0;
	t = *stack;
	while (t)
	{
		if (*(int *)t->content == current)
			break ;
		t = t->next;
		i++;
	}
	return (i);
}

int	get_next_smaller(t_list **stack, int *current)
{
	t_list	*t;
	int		min;

	t = *stack;
	min = get_min(stack);
	while (t)
	{
		if (*(int *)t->content > min && *(int *)t->content < *current)
			min = *(int *)t->content;
		t = t->next;
	}
	return (min);
}
