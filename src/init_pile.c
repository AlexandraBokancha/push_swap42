/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:05:37 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 19:17:58 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack_a)
{
	t_list	*head;
	t_list	*current;

	if (*stack_a != NULL)
	{
		head = (*stack_a)->next;
		while (head != NULL)
		{	
			current = head;
			head = head->next;
			free(current);
		}
		free(*stack_a);
		*stack_a = NULL;
	}
}

static void	insert_node(t_list **stack, int data)
{
	t_list	*node;
	t_list	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = data;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = node;
		node->prev = last;
	}
}

static void	push_data(char **tab, t_list **stack, int i)
{	
	long long int	data;

	while (tab[i])
	{	
		data = ft_atoll(tab[i]);
		insert_node(stack, (int)data);
		i++;
	}
}

void	check_and_push(char **tab, t_list **stack, int len, int i)
{
	if (check_av(len, i, tab) == -1)
	{
		if (i == 0)
			ft_free(tab, len);
		ft_printf("Error\n");
		exit (0);
	}
	push_data(tab, stack, i);
	if (i == 0)
		ft_free(tab, len);
}

int	init_stack_a(t_list **stack, char **args, int len)
{
	char	**tab;
	int		i;

	i = 0;
	if (len < 2)
		exit (0);
	if (len == 2)
	{
		tab = ft_split(args[1], ' ');
		len = count_word(args[1]);
		if (len < 1)
		{	
			ft_free(tab, len);
			ft_printf("Error\n");
			exit (0);
		}
	}
	else
	{	
		i = 1;
		tab = args;
	}
	check_and_push(tab, stack, len, i);
	return (0);
}
