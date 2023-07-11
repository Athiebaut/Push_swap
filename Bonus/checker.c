/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:35 by athiebau          #+#    #+#             */
/*   Updated: 2023/07/11 11:36:38 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	print_result(t_stack **pile_a, t_stack **pile_b)
{
	if (!check_sorted(pile_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	commands(char *line, t_stack **pile_a, t_stack **pile_b)
{
	if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		return (rotate_a(pile_a, 1));
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		return (rotate_b(pile_b, 1));
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		return (rotate_r(pile_a, pile_b, 1));
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		return (reverse_rotate_a(pile_a, 1));
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		return (reverse_rotate_b(pile_b, 1));
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		return (reverse_rotate_r(pile_a, pile_b, 1));
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		return (swap_a(pile_a, 1));
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		return (swap_b(pile_b, 1));
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		return (swap_s(pile_a, pile_b, 1));
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		return (push_a(pile_a, pile_b, 1));
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		return (push_b(pile_a, pile_b, 1));
	else
		return (-1);
}

int	time_to_read(t_stack **pile_a, t_stack **pile_b)
{
	char	*line;

	line = get_next_line(0, 0);
	while (line)
	{
		if (commands(line, pile_a, pile_b) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			get_next_line(0, 1);
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(0, 0);
	}
	free(line);
	return (0);
}

void	checker(int ac, char **av)
{
	t_stack	**pile_a;
	t_stack	**pile_b;

	check_args(av);
	pile_a = (t_stack **)malloc(sizeof(t_stack));
	if (!pile_a)
		return ;
	pile_b = (t_stack **)malloc(sizeof(t_stack));
	if (!pile_b)
	{
		free(pile_a);
		return ;
	}
	*pile_a = NULL;
	*pile_b = NULL;
	init_stack(pile_a, av);
	if (!check_sorted(pile_a))
	{
		print_result(pile_a, pile_b);
		ft_free(pile_a, pile_b);
		return ;
	}
	if (!time_to_read(pile_a, pile_b))
		print_result(pile_a, pile_b);
	ft_free(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac < 2)
		return (-1);
	else
	{
		av++;
		if (ac == 2)
		{
			if (*av[0] == '\0')
				return (0);
			av = ft_split(*av, ' ');
			ac = ft_strlen2(av);
			if (ac == 0)
				return (0);
			checker(ac, av);
			while (av[++i])
				free(av[i]);
			free(av);
		}
		else
			checker(ac, av);
	}
	return (0);
}
