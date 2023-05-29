/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_outils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 18:44:12 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_continue5(t_stack **stack_a, t_stack **stack_b, int flg)
{
	(void)stack_b;
	if (flg == 1)
		ft_sa(stack_a);
	else if (flg == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (flg == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (flg == 4)
		ft_rra(stack_a);
	return ;
}

void	ft_continue4(t_stack **stack_a, t_stack **stack_b, int flg)
{
	if (flg == 1)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (flg == 2)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (flg == 3)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	return ;
}

void	ft_continue3(t_stack **stack, t_stack *sec_lst, int counter)
{
	if (counter == 2 && sec_lst->index == 2)
		ft_rra(stack);
	else if (counter == 1 && sec_lst->next->index == 2)
		ft_sa(stack);
	else if (counter == 1 && sec_lst->next->index == 1)
		ft_ra(stack);
	else if (counter == 0 && sec_lst->index == 2)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	return ;
}
