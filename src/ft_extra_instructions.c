/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:09:02 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 18:39:16 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_sa(t_stack **stack)
{
	if (ft_swap(stack))
	{
		write(1, "sa\n", 3);
		return (1);
	}
	else
		return (0);
}

int	ft_sb(t_stack **stack)
{
	if (ft_swap(stack))
	{
		write(1, "sb\n", 3);
		return (1);
	}
	else
		return (0);
}

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

int	ft_ra(t_stack **stack)
{
	if (ft_rotate(stack))
	{
		write(1, "ra\n", 3);
		return (1);
	}
	else
		return (0);
}

int	ft_rb(t_stack **stack)
{
	if (ft_rotate(stack))
	{
		write(1, "rb\n", 3);
		return (1);
	}
	else
		return (0);
}
