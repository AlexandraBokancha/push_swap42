/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:34:01 by albokanc          #+#    #+#             */
/*   Updated: 2024/03/12 19:46:02 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '0')
			return (-1);
		if ((ft_isdigit(str[i]) == 0) || i > 1)
			return (-1);
	}	
	return (0);
}

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
			i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_double(char *s1, char *s2)
{
	int	nb1;
	int	nb2;

	nb1 = ft_atoi(s1);
	nb2 = ft_atoi(s2);
	if (nb1 == nb2)
		return (-1);
	return (0);
}

int	check_max_min(char *str)
{
	if (ft_atoll(str) > INT_MAX || ft_atoll(str) < INT_MIN)
		return (-1);
	return (0);
}

int	check_av(int len, int i, char **args)
{
	int	j;

	while (i < len)
	{
		j = i + 1;
		if (args[i][0] == '\0')
			return (-1);
		while (j < len)
		{
			if (check_double(args[i], args[j]) == -1 && len != 1)
				return (-1);
			j++;
		}
		if (check_sign(args[i]) == -1 || check_numeric(args[i]) == -1
			|| check_max_min(args[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
