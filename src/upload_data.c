/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:09:26 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 19:10:26 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_cheapest(t_list *stack)
{
	long	value;
	t_list	*node;

	if (!stack)
		return (NULL);
	value = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < value)
		{
			value = stack->push_price;
			node = stack;
		}
		stack = stack->next;
	}
	node->cheapest = true;
	return (node);
}

void	push_price(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_price = a->index;
		if (!(a->above_median))
			a->push_price = len_a - (a->index);
		if (a->target->above_median)
			a->push_price += a->target->index;
		else
			a->push_price += len_b - a->target->index;
		a = a->next;
	}
}

void	check_before_push(t_list **stack, t_list *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	upload_stack_a(t_list *a, t_list *b)
{
	find_index(a);
	find_index(b);
	set_target_a(a, b);
	push_price(a, b);
	set_cheapest(a);
}

void	upload_stack_b(t_list *a, t_list *b)
{
	find_index(a);
	find_index(b);
	set_target_b(a, b);
}
