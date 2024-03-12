/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:59:16 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 18:44:04 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_top(t_list **a)
{
	while ((*a)->nb != find_min(*a)->nb)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack != NULL)
	{
		if (max->nb < stack->nb)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*find_min(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (min->nb > stack->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	sort3(t_list **stack_a)
{
	t_list	*max;

	max = find_max(*stack_a);
	if (max == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == max)
		rra(stack_a);
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		sa(stack_a);
	return (0);
}
