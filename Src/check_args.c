/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:13:05 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/06 17:34:24 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_free(t_stack **pile_a, t_stack **pile_b)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *pile_a;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(pile_a);
	node = *pile_b;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(pile_b);
}

int	check_doubles(int num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+') && (ft_strlen(num) == 1))
		return (0);
	if (num[i] == '-' && (num[i + 1] > '9' || num[i + 1] < '0'))
		return (0);
	if (num[i] == '+')
		return (0);
	i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(char **av)
{
	char	**args;
	char	*str;
	int		i;
	int		tmp;

	args = av;
	i = 0;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		str = ft_itoa(tmp);
		if (ft_strncmp(str, args[i], ft_strlen(args[i]) != 0))
		{
			free(str);
			error_handler();
		}
		else
			free(str);
		if (!ft_is_num(args[i]))
			error_handler();
		if (!check_doubles(tmp, args, i))
			error_handler();
		i++;
	}
}
