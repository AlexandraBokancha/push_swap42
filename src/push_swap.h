/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:35:35 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 19:09:18 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647 
# define INT_MIN -2147483648

# include "../libs/printf/ft_printf.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// stacks are double linked list 

typedef struct s_list
{
	int				nb;
	int				index;
	int				push_price;
	int				median;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

// functions to handle errors 

int				check_av(int len, int i, char **args);
int				check_sign(char *str);
int				check_numeric(char *str);
int				check_double(char *s1, char *s2);
int				check_max_min(char *str);

// functions to handle a linked list

t_list			*find_max(t_list *stack);
t_list			*find_min(t_list *stack);
t_list			*last_node(t_list *stack);
void			find_index(t_list *stack);
void			free_stack(t_list **stack_a);
int				init_stack_a(t_list **stack, char **args, int index);
int				ft_lstsize(t_list *lst);
int				if_sorted(t_list *stack);

// helpful funcitons from my libft

char			**ft_split(char const *s, char c);
int				count_word(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
int				is_word(char c);
int				is_space(char c);
int				ft_atoi(char *nptr);
char			*ft_itoa(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_free(char **tab, int len);
long long int	ft_atoll(char *nptr);

// calculation

t_list			*set_cheapest(t_list *stack);
void			push_price(t_list *a, t_list *b);
void			check_before_push(t_list **stack, t_list *top, char name);
void			set_target_a(t_list *a, t_list *b);
void			set_target_b(t_list *a, t_list *b);

// operations

int				sa(t_list **a);
int				sb(t_list **b);
int				ss(t_list **a, t_list **b);
int				pa(t_list **a, t_list **b);
int				pb(t_list **a, t_list **b);
int				ra(t_list **a);
int				rb(t_list **b);
int				rr(t_list **a, t_list **b);
int				rra(t_list **a);
int				rrb(t_list **b);
int				rrr(t_list **a, t_list **b);
void			reverse_rotate_ab(t_list **a, t_list **b, t_list *cheapest);
void			rotate_ab(t_list **a, t_list **b, t_list *cheapest_node);
void			push_to_top(t_list **a);

// algorithm

int				sort3(t_list **a);
void			turkish_algo(t_list **a, t_list **b);
void			upload_stack_a(t_list *a, t_list *b);
void			upload_stack_b(t_list *a, t_list *b);

#endif