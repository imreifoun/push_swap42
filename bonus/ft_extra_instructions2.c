/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_instructions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 17:10:34 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push_a_to_b(stack_a, stack_b))
		return (1);
	return (0);
}

int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push_a_to_b(stack_b, stack_a))
		return (1);
	return (0);
}
