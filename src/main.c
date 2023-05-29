/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 17:32:55 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_nodes(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	ft_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(STDERR_FILENO, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

bool	ft_is_sorted(t_stack **stack_a)
{
	t_stack	*curr;
	int		next_nbr;
	bool	is_sorted;
	int		nbr;

	curr = *stack_a;
	is_sorted = 0;
	while (curr && curr->next)
	{
		nbr = curr->nbr;
		next_nbr = curr->next->nbr;
		if (nbr > next_nbr)
			is_sorted = 1;
		curr = curr->next;
	}
	return (is_sorted);
}

void	ft_start_sorting(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		ft_3_nbr(stack_a);
	else if (size == 4)
		ft_4_nbr(stack_a, stack_b);
	else if (size == 5)
		ft_5_nbr(stack_a, stack_b);
	else
		ft_clear_stack(stack_a, stack_b);
}

int	main(int argc, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;
	bool	is_sorted;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (argc < 2 || !stack_a || !stack_b)
		exit(ft_error("Error"));
	*stack_a = NULL;
	*stack_b = NULL;
	args = join_args(av);
	if (ft_arg_checker(args))
		exit(ft_error("Error"));
	ft_init_stack(stack_a, args);
	ft_free(args);
	ft_list_index(stack_a);
	is_sorted = ft_is_sorted(stack_a);
	if (is_sorted)
		ft_start_sorting(stack_a, stack_b, ft_lstsize(stack_a));
	free_nodes(*stack_a);
	exit(0);
	return (0);
}
