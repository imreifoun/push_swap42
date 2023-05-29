/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 18:43:24 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_largest_num(t_stack *stack)
{
	int	max;

	max = stack->index;
	stack = stack->next;
	while (stack != NULL)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_position(t_stack *stack)
{
	int	pos;
	int	lenght;
	int	max;

	pos = -1;
	max = stack->index;
	stack = stack->next;
	lenght = 0;
	while (stack != NULL)
	{
		if (max < stack->index)
		{
			max = stack->index;
			pos = lenght;
		}
		stack = stack->next;
		lenght++;
	}
	lenght = lenght / 2;
	if (pos < lenght)
		return (0);
	return (1);
}

int	top_index(t_stack *stack)
{
	int		max_index;
	t_stack	*current;

	current = stack->next;
	max_index = stack->index;
	if (stack == NULL)
		return (0);
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (stack->index == max_index);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	max;

	max = 0;
	position = 0;
	while (*stack_b != NULL)
	{
		max = find_largest_num(*stack_b);
		position = find_position(*stack_b);
		if (position == 0)
		{
			if (max == (*stack_b)->index && top_index(*stack_b))
				ft_pa(stack_a, stack_b);
			else
				ft_rb(stack_b);
		}
		else if (position == 1)
			ft_rrb(stack_b);
	}
}

void	ft_clear_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;

	i = 0;
	if (ft_lstsize(stack_a) <= 100)
		j = 19;
	else
		j = 37;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + j)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
	sort(stack_a, stack_b);
}
