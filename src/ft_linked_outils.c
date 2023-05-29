/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/23 18:40:24 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_lstsize(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = (*stack);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	ft_print_list(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		ft_putnbr_fd(tmp->nbr, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	return ;
}

t_stack	*ft_lstlast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_lst_addback(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!(*stack))
		*stack = node;
	else
	{
		last = ft_lstlast(*stack);
		last->next = node;
	}
}

t_stack	*ft_addnew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;
	new->next = NULL;
	return (new);
}
