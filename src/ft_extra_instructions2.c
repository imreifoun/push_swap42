/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_instructions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:09:10 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 18:39:31 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push_a_to_b(stack_a, stack_b))
	{
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push_a_to_b(stack_b, stack_a))
	{
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}
