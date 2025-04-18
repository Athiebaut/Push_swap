/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:58:41 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:12:51 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * push_swap - Main function to sort a stack using the push_swap algorithm.
 * 
 * @ac: The argument count (not used in this function but typically passed in).
 * @av: The argument vector containing the stack elements as strings.
 * 
 * This function performs the following steps:
 * 1. Validates the input arguments using `check_args`.
 * 2. Allocates memory for two stacks (`pile_a` and `pile_b`).
 * 3. Initializes `pile_a` with the input values and sets `pile_b` to NULL.
 * 4. Checks if the stack is already sorted using `check_sorted`.
 *    - If sorted, it frees the allocated memory and exits.
 * 5. If not sorted, it sorts the stack using the `sort` function.
 * 6. Frees all allocated memory before exiting.
 * 
 * Note:
 * - Memory allocation failures are handled to prevent leaks.
 * - The function assumes that `check_args`, `init_stack`, `check_sorted`, 
 *   `sort`, and `ft_free` are implemented elsewhere in the program.
 */
void	push_swap(int ac, char **av)
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
		ft_free(pile_a, pile_b);
		return ;
	}	
	sort(pile_a, pile_b);
	ft_free(pile_a, pile_b);
}

/**
 * @file push_swap.c
 * @brief Entry point for the Push_swap program.
 *
 * This file contains the main function that serves as the entry point
 * for the Push_swap program. It handles input validation, argument parsing,
 * and calls the core functionality of the program.
 *
 * @param ac The argument count passed to the program.
 * @param av The argument vector containing the program arguments.
 *
 * @return Returns 0 on successful execution, -1 if the argument count is less than 2,
 *         or 0 if the input is empty or invalid.
 *
 * The program performs the following steps:
 * - Validates the number of arguments.
 * - If a single argument is provided, it splits the argument into an array
 *   of strings using `ft_split` and calculates the new argument count.
 * - Calls the `push_swap` function to perform the sorting logic.
 * - Frees allocated memory for the split arguments if applicable.
 */
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
			push_swap(ac, av);
			while (av[++i])
				free(av[i]);
			free(av);
		}
		else
			push_swap(ac, av);
	}
	return (0);
}
