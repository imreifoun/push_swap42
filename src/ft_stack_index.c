/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 16:52:54 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_next_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*curr;

	min = NULL;
	curr = *stack;
	while (curr)
	{
		while (curr && curr->index != -1)
			curr = curr->next;
		if (curr == NULL)
			return (min);
		if (min == NULL || curr->nbr < min->nbr)
			min = curr;
		curr = curr->next;
	}
	return (min);
}

void	ft_list_index(t_stack **stack)
{
	t_stack	*next_min;
	t_stack	*curr;
	int		index;

	index = 0;
	curr = *stack;
	next_min = NULL;
	while (curr)
	{
		next_min = ft_next_min(stack);
		next_min->index = index++;
		curr = curr->next;
	}
	return ;
}

int	ft_abs(int x, int negv)
{
	if (negv)
		return (-x);
	else
		return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	str[12];
	int		negv;

	negv = (n < 0);
	ft_bzero(str, 12);
	len = 0;
	if (n == 0)
		str[len] = '0';
	while (n != 0)
	{
		str[len++] = '0' + ft_abs(n % 10, negv);
		n /= 10;
	}
	if (negv)
		str[len] = '-';
	else if (len > 0)
		len--;
	while (len >= 0)
		write(fd, &str[len--], 1);
}

int	ft_protect_atoi(long number, int sign)
{
	if (number > INT_MAX)
		exit(ft_error("Error"));
	else if (number < INT_MIN)
		exit(ft_error("Error"));
	else
		return (((int)number) * sign);
}
