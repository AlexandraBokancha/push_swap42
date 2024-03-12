/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:59:43 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 19:17:15 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_a(t_list **a, t_list **b)
{
	check_before_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = set_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_ab(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_ab(a, b, cheapest_node);
	check_before_push(a, cheapest_node, 'a');
	check_before_push(b, cheapest_node->target, 'b');
	pb(a, b);
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list		*current_a;
	t_list		*target;
	long int	i;

	while (b)
	{
		current_a = a;
		i = LONG_MAX;
		while (current_a)
		{
			if (current_a->nb > b->nb && current_a->nb < i)
			{
				i = current_a->nb;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (i == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target;
	long	i;

	while (a)
	{
		current_b = b;
		i = LONG_MIN;
		while (current_b)
		{
			if (current_b->nb < a->nb && current_b->nb > i)
			{
				i = current_b->nb;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (i == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	turkish_algo(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (len-- > 3 && (if_sorted(*a) == 1))
		pb(a, b);
	if (len-- > 3 && (if_sorted(*a) == 1))
		pb(a, b);
	while (len-- > 3 && (if_sorted(*a) == 1))
	{
		upload_stack_a(*a, *b);
		to_b(a, b);
	}
	sort3(a);
	while (*b)
	{
		upload_stack_b(*a, *b);
		to_a(a, b);
	}
	find_index(*a);
	push_to_top(a);
}
