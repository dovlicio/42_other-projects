/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:57:20 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/14 18:03:36 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_error(int *number)
{
	if (!number)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static void	check_malloc_exit(t_list **stack_a, int *number)
{
	if (!number || !(*stack_a))
	{
		if (!number)
			free_stack(stack_a);
		else
		{
			free(number);
			free_stack(stack_a);
		}
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static void	check_duplicates(t_list **stack_a)
{
	int		*current_int;
	int		*next_int;
	t_list	*start;
	t_list	*next;

	start = *stack_a;
	while (start)
	{
		next = start->next;
		current_int = start->content;
		while (next)
		{
			next_int = next->content;
			if (*current_int == *next_int)
			{
				free_stack(stack_a);
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			next = next->next;
		}
		start = start->next;
	}
}

static void	check_malloc_stack(t_list **stack_a, t_list *stack, int *n)
{
	if (!stack)
	{
		free(n);
		free_stack(stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	put_args_in_stack(char **argv, t_list **stack_a)
{
	t_list	*start;
	int		i;
	int		*number;

	i = 1;
	number = (int *)ft_calloc(sizeof(int), 1);
	check_error(number);
	*number = ft_atoi(argv[i++], stack_a, number);
	*stack_a = ft_lstnew(number);
	check_malloc_exit(stack_a, number);
	start = *stack_a;
	while (argv[i])
	{
		number = (int *)ft_calloc(sizeof(int), 1);
		check_malloc_exit(stack_a, number);
		*number = ft_atoi(argv[i++], stack_a, number);
		start->next = ft_lstnew(number);
		check_malloc_stack(stack_a, (start->next), number);
		start = start->next;
	}
	check_duplicates(stack_a);
}
