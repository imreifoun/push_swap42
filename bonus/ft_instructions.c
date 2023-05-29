/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 17:10:53 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_rotate(stack_a) && ft_rotate(stack_b))
		return (1);
	return (0);
}

int	ft_rra(t_stack **stack)
{
	if (ft_rev_rotate(stack))
		return (1);
	else
		return (0);
}

int	ft_rrb(t_stack **stack)
{
	if (ft_rev_rotate(stack))
		return (1);
	else
		return (0);
}

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_rev_rotate(stack_a) && ft_rev_rotate(stack_b))
		return (1);
	return (0);
}
