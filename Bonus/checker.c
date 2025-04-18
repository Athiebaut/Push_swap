/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:35 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 01:20:59 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Prints the result of the sorting check for the given stacks.
 * 
 * This function checks if the stack `pile_a` is sorted and prints "OK" if it is,
 * or "KO" if it is not. The function assumes that `pile_b` is empty or irrelevant
 * for the sorting check.
 * 
 * @param pile_a A double pointer to the first stack (stack A).
 * @param pile_b A double pointer to the second stack (stack B).
 */
void	print_result(t_stack **pile_a, t_stack **pile_b)
{
	if (!check_sorted(pile_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/**
 * @brief Executes a command on the given stacks based on the input line.
 *
 * This function takes a command string (line) and performs the corresponding
 * operation on the provided stacks (pile_a and pile_b). The function supports
 * various stack operations such as rotations, swaps, and pushes.
 *
 * @param line A string representing the command to execute. The command must
 *             end with a newline character ('\n').
 * @param pile_a A pointer to the first stack (t_stack) to operate on.
 * @param pile_b A pointer to the second stack (t_stack) to operate on.
 *
 * @return Returns 1 if the command is successfully executed, or -1 if the
 *         command is invalid.
 *
 * Supported commands:
 * - "ra\n": Rotate stack A.
 * - "rb\n": Rotate stack B.
 * - "rr\n": Rotate both stacks A and B.
 * - "rra\n": Reverse rotate stack A.
 * - "rrb\n": Reverse rotate stack B.
 * - "rrr\n": Reverse rotate both stacks A and B.
 * - "sa\n": Swap the top two elements of stack A.
 * - "sb\n": Swap the top two elements of stack B.
 * - "ss\n": Swap the top two elements of both stacks A and B.
 * - "pa\n": Push the top element from stack B to stack A.
 * - "pb\n": Push the top element from stack A to stack B.
 */
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

/**
 * time_to_read - Reads commands from standard input and executes them on the stacks.
 * 
 * This function reads lines of input using `get_next_line` and processes each line
 * as a command to manipulate the given stacks `pile_a` and `pile_b`. If an invalid
 * command is encountered, it prints an error message to standard error, cleans up
 * resources, and returns an error code.
 * 
 * @param pile_a A pointer to the first stack (t_stack **).
 * @param pile_b A pointer to the second stack (t_stack **).
 * 
 * @return Returns 0 on success, or -1 if an invalid command is encountered.
 * 
 * Behavior:
 * - Reads input line by line using `get_next_line`.
 * - Passes each line to the `commands` function to execute the corresponding operation.
 * - If `commands` returns -1 (indicating an error), prints "Error\n" to standard error,
 *   frees allocated memory, and terminates the function with a return value of -1.
 * - Frees each line after processing it.
 * - Ensures proper cleanup by calling `get_next_line` with a reset flag (1) in case of error.
 */
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

/**
 * @brief Main function for the checker program. Validates input arguments,
 *        initializes stacks, and processes operations to check if the stack
 *        is sorted.
 * 
 * @param ac Argument count (not used in this function).
 * @param av Argument vector containing the input values for the stack.
 * 
 * @details This function performs the following steps:
 *          1. Validates the input arguments using `check_args`.
 *          2. Allocates memory for two stacks (`pile_a` and `pile_b`).
 *          3. Initializes `pile_a` with the input values and sets `pile_b` to NULL.
 *          4. Checks if the stack is already sorted using `check_sorted`.
 *             - If sorted, it prints the result and frees the allocated memory.
 *          5. Reads and processes operations using `time_to_read`.
 *             - If operations are valid, it prints the result.
 *          6. Frees all allocated memory using `ft_free`.
 * 
 * @note If memory allocation fails at any point, the function ensures proper
 *       cleanup to avoid memory leaks.
 */
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

/**
 * @file checker.c
 * @brief Entry point for the checker program in the Push_swap project.
 *
 * This program validates and processes input arguments for the Push_swap bonus checker.
 * It handles both single string arguments (split into multiple values) and multiple arguments.
 * The program ensures proper memory management and calls the `checker` function to perform
 * the necessary operations.
 *
 * @param ac The argument count passed to the program.
 * @param av The argument vector containing the input values.
 *
 * @return Returns 0 on successful execution, -1 if the argument count is less than 2,
 *         or 0 if the input is empty after processing.
 *
 * @note The function uses `ft_split` to split a single string argument into multiple values
 *       and `ft_strlen2` to calculate the number of resulting strings. It also ensures
 *       proper memory cleanup for dynamically allocated memory.
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
