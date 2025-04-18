/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:13:05 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:10:32 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Handles errors by printing an error message to the standard error
 *        output and terminating the program.
 *
 * This function is typically called when an invalid condition is encountered
 * in the program. It writes the message "Error\n" to file descriptor 2 (stderr)
 * and then exits the program with a status code of 0.
 *
 * @note The program will terminate immediately after calling this function.
 */
void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

/**
 * @brief Frees the memory allocated for two stacks and their nodes.
 *
 * This function deallocates all the memory used by the nodes in the two stacks
 * (`pile_a` and `pile_b`) and then frees the memory allocated for the stack pointers themselves.
 *
 * @param pile_a A double pointer to the first stack (t_stack **).
 * @param pile_b A double pointer to the second stack (t_stack **).
 *
 * @note Both `pile_a` and `pile_b` must be dynamically allocated and their nodes
 *       must also be dynamically allocated. Passing invalid pointers or non-dynamically
 *       allocated memory may result in undefined behavior.
 */
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

/**
 * check_doubles - Checks for duplicate numbers in an array of strings.
 * 
 * @num: The number to check for duplicates.
 * @args: The array of strings containing numbers to compare.
 * @i: The starting index in the array to begin the check.
 * 
 * This function iterates through the array of strings starting from the
 * index `i + 1` and compares each element, converted to an integer using
 * `ft_atoi`, with the given number `num`. If a duplicate is found, the
 * function returns 0. If no duplicates are found, it returns 1.
 * 
 * Return: 
 * - 0 if a duplicate of `num` is found in the array.
 * - 1 if no duplicates are found.
 */
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

/**
 * ft_is_num - Checks if a given string represents a valid integer number.
 * 
 * @num: The string to be checked.
 * 
 * This function verifies if the input string represents a valid integer.
 * It allows an optional '+' or '-' sign at the beginning, followed by
 * numeric digits. The function returns 0 if:
 * - The string contains only a '+' or '-' without any digits.
 * - The string starts with a '-' but is not followed by a digit.
 * - The string starts with a '+' (not allowed in this implementation).
 * - Any non-digit character is found in the string.
 * Otherwise, it returns 1, indicating the string is a valid integer.
 * 
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
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

/**
 * @brief Validates the arguments passed to the program.
 *
 * This function checks if the arguments provided are valid integers, 
 * do not contain non-numeric characters, and do not have duplicates.
 * If any of these conditions fail, the function calls `error_handler()`.
 *
 * @param av A null-terminated array of strings representing the arguments.
 *
 * The function performs the following checks:
 * 1. Converts each argument to an integer using `ft_atoi` and back to a string 
 *    using `ft_itoa` to ensure the argument is a valid integer representation.
 * 2. Compares the original argument with the converted string using `ft_strncmp`.
 * 3. Verifies that the argument contains only numeric characters using `ft_is_num`.
 * 4. Checks for duplicate integers in the argument list using `check_doubles`.
 *
 * If any of these checks fail, the function calls `error_handler()` to handle the error.
 */
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
