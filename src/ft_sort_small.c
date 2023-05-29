/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 15:33:45 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_index_checker(t_stack **stack)
{
	t_stack	*tmp;
	int		counter;

	tmp = *stack;
	counter = 0;
	while (tmp && tmp->index != 0)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

void	ft_3_nbr(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*sec_lst;
	int			counter;

	tmp = *stack;
	counter = ft_index_checker(stack);
	while (tmp->next)
	{
		sec_lst = tmp;
		tmp = tmp->next;
	}
	if (counter == 2 && sec_lst->index == 1)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else
		ft_continue3(stack, sec_lst, counter);
}

void	ft_re_index(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	ft_list_index(stack_a);
}

void	ft_4_nbr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		flg;

	min = *stack_a;
	flg = 0;
	while (min && min->index != 0)
	{
		flg++;
		min = min->next;
	}
	if (flg == 0)
		ft_pb(stack_a, stack_b);
	else
		ft_continue4(stack_a, stack_b, flg);
	ft_re_index(stack_a);
	ft_3_nbr(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_5_nbr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		flg;

	min = *stack_a;
	flg = 0;
	while (min && min->index != 0)
	{
		flg++;
		min = min->next;
	}
	if (flg == 0)
		ft_pb(stack_a, stack_b);
	else
	{
		ft_continue5(stack_a, stack_b, flg);
		ft_pb(stack_a, stack_b);
	}
	ft_re_index(stack_a);
	ft_4_nbr(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	return ;
}
