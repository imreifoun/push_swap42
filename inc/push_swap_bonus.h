/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 16:37:38 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				size;
	int				nbr;
	int				index;
	struct s_stack	*next;

}t_stack;

int		ft_pb(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_find_sec_last(t_stack **stack);
int		ft_rev_rotate(t_stack **stack);
int		ft_rotate(t_stack **stack);
int		ft_push_a_to_b(t_stack **stack_a, t_stack **stack_b);
int		ft_swap(t_stack **stack_a);
t_stack	*ft_addnew(int nbr);
void	ft_lst_addback(t_stack **stack, t_stack *node);
t_stack	*ft_lstlast(t_stack *head);
void	ft_print_list(t_stack **stack);
int		ft_lstsize(t_stack *stack);
int		ft_is_sorted(t_stack **stack_a);
t_stack	*ft_find_last(t_stack **stack);
int		ft_rr(t_stack **stack_a, t_stack **stack_b);
int		ft_rra(t_stack **stack);
int		ft_rrb(t_stack **stack);
int		ft_rrr(t_stack **stack_a, t_stack **stack_b);
int		ft_pa(t_stack **stack_a, t_stack **stack_b);
int		ft_sa(t_stack **stack);
int		ft_sb(t_stack **stack);
int		ft_ss(t_stack **stack_a, t_stack **stack_b);
int		ft_ra(t_stack **stack);
int		ft_rb(t_stack **stack);
void	ft_init_stack(t_stack **stack, char **av);
void	ft_valid_nbr(char **argv);
int		ft_is_duplicated(char **argv, int nbr);
int		ft_arg_checker(char **av);
char	*get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
char	**ft_split(const char *str, char c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		check(t_stack **stacka, t_stack **stackb, char *line);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_error(char *msg);
char	**join_args(char **argv);
void	ft_free(char **str);
void	free_nodes(t_stack *stack);
int		ft_abs(int x, int negv);
void	ft_putnbr_fd(int n, int fd);
void	ft_print_list(t_stack **stack);
int		ft_protect_atoi(long number, int sign);

#endif
