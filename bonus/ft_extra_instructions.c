/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 17:10:22 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	ft_sa(t_stack **stack)
{
	if (ft_swap(stack))
		return (1);
	else
		return (0);
}

int	ft_sb(t_stack **stack)
{
	if (ft_swap(stack))
		return (1);
	else
		return (0);
}

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
		return (1);
	return (0);
}

int	ft_ra(t_stack **stack)
{
	if (ft_rotate(stack))
		return (1);
	else
		return (0);
}

int	ft_rb(t_stack **stack)
{
	if (ft_rotate(stack))
		return (1);
	else
		return (0);
}
