/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 17:11:11 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_swap(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*rest;

	first = *stack_a;
	second = first->next;
	rest = second->next;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	first->next = rest;
	second->next = first;
	*stack_a = second;
	return (1);
}

int	ft_push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*head_a;
	t_stack		*head_b;
	t_stack		*tmp;
	int			size;

	head_a = *stack_a;
	head_b = *stack_b;
	size = ft_lstsize(*stack_b);
	if (size == 0)
		return (0);
	tmp = head_b;
	head_b = head_b->next;
	*stack_b = head_b;
	if (head_a == NULL)
	{
		head_a = tmp;
		head_a->next = NULL;
		(*stack_a) = head_a;
	}
	else
	{
		tmp->next = head_a;
		(*stack_a) = tmp;
	}
	return (1);
}

int	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	if (*stack == NULL || stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	head = (*stack);
	last = ft_find_last(stack);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (1);
}

int	ft_rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*sec_last;

	if (*stack == NULL || stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	last = ft_find_last(stack);
	sec_last = ft_find_sec_last(stack);
	last->next = *stack;
	sec_last->next = NULL;
	*stack = last;
	return (1);
}

t_stack	*ft_find_sec_last(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->next->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
