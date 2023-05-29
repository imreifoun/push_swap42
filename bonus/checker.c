/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 17:39:42 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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

int	check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		ft_push_a_to_b(stack_a, stack_b);
	else if (!ft_strcmp(line, "sa\n"))
		ft_sa(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sb(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ft_ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		ft_push_a_to_b(stack_b, stack_a);
	else if (!ft_strcmp(line, "ra\n"))
		ft_ra(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rb(stack_b);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrb(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rrr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rra(stack_a);
	else
		exit(ft_error("Error"));
	return (0);
}

void	check_print(t_stack **stack_a, int key)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (!*stack_a)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	tmp->size = ft_lstsize(*stack_a);
	if (key != 0)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	if (ft_is_sorted(stack_a) && ft_lstsize(*stack_a) == tmp->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_nodes(*stack_a);
}

int	main(int argc, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	char	**args;

	if (argc < 2 || !av[1][0])
		exit(ft_error("Error"));
	stack_a = NULL;
	stack_b = NULL;
	args = join_args(av);
	if (ft_arg_checker(args))
	{
		ft_free(args);
		exit(ft_error("Error"));
	}
	ft_init_stack(&stack_a, args);
	ft_free(args);
	while (get_next_line(0, &line))
	{
		check(&stack_a, &stack_b, line);
		free(line);
	}
	check_print(&stack_a, ft_lstsize(stack_b));
	return (0);
}
