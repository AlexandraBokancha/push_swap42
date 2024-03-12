/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:37:27 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 19:18:38 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_reverse(t_list **stack)
{
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (-1);
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	return (0);
}

int	rra(t_list **stack_a)
{
	rotate_reverse(stack_a);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	rotate_reverse(stack_b);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
	ft_putstr_fd("rrr\n", 1);
	return (0);
}

void	reverse_rotate_ab(t_list **a, t_list **b, t_list *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	find_index(*a);
	find_index(*b);
}
