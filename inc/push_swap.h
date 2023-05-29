/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/05/27 16:37:29 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;

}t_stack;

void	ft_valid_nbr(char **argv);
void	ft_init_stack(t_stack **stack, char **argv);
int		ft_is_duplicated(char **argv, int nbr);
int		ft_arg_checker(char **av);
void	ft_lst_addback(t_stack **stack, t_stack *node);
t_stack	*ft_addnew(int nbr);
t_stack	*ft_lstlast(t_stack *head);
void	ft_print_list(t_stack **stack);
t_stack	*ft_next_min(t_stack **stack);
void	ft_list_index(t_stack **stack);
int		ft_lstsize(t_stack **stack);
t_stack	*ft_find_sec_last(t_stack **stack);
t_stack	*ft_find_last(t_stack **stack);
bool	ft_is_sorted(t_stack **stack_a);
int		ft_rev_rotate(t_stack **stack);
int		ft_rotate(t_stack **stack);
int		ft_push_a_to_b(t_stack **stack_a, t_stack **stack_b);
int		ft_swap(t_stack **stack_a);
int		ft_ra(t_stack **stack);
int		ft_rb(t_stack **stack);
int		ft_rr(t_stack **stack_a, t_stack **stack_b);
int		ft_rra(t_stack **stack);
int		ft_rrb(t_stack **stack);
int		ft_rrr(t_stack **stack_a, t_stack **stack_b);
int		ft_sa(t_stack **stack);
int		ft_sb(t_stack **stack);
int		ft_ss(t_stack **stack_a, t_stack **stack_b);
int		ft_pa(t_stack **stack_a, t_stack **stack_b);
int		ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_re_index(t_stack **stack_a);
int		ft_index_checker(t_stack **stack);
void	ft_continue3(t_stack **stack, t_stack *sec_lst, int counter);
void	ft_continue4(t_stack **stack_a, t_stack **stack_b, int flg);
void	ft_continue5(t_stack **stack_a, t_stack **stack_b, int flg);
void	ft_3_nbr(t_stack **stack);
void	ft_4_nbr(t_stack **stack_a, t_stack **stack_b);
void	ft_5_nbr(t_stack **stack_a, t_stack **stack_b);
void	ft_clear_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_start_sorting(t_stack **stack_a, t_stack **stack_b, int size);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		top_index(t_stack *stack);
int		find_position(t_stack *stack);
int		find_largest_num(t_stack *stack);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
char	**ft_split(const char *str, char c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
void	check_str(const char *str);
void	ft_free(char **str);
void	free_nodes(t_stack *stack);
char	**join_args(char **argv);
int		ft_error(char *msg);
int		ft_abs(int x, int negv);
void	ft_putnbr_fd(int n, int fd);
int		ft_protect_atoi(long number, int sign);

#endif