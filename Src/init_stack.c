/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:56:13 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:11:31 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * ft_strlen2 - Calculates the number of strings in a null-terminated array of strings.
 * 
 * @str: A pointer to an array of strings (char **), where each element is a 
 *       null-terminated string, and the array itself is terminated by a NULL pointer.
 * 
 * Return: The number of strings in the array (size_t).
 * 
 * Note: This function assumes that the input array is properly null-terminated.
 */
size_t	ft_strlen2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * check_sorted - Checks if a stack is sorted in ascending order.
 * @pile_a: A double pointer to the head of the stack (linked list).
 *
 * This function iterates through the stack and compares the value of each
 * node with the value of the next node. If it finds a node whose value
 * is greater than the next node's value, it returns 1, indicating that
 * the stack is not sorted. If the entire stack is traversed without
 * finding such a case, it returns 0, indicating that the stack is sorted.
 *
 * Return: 1 if the stack is not sorted, 0 if it is sorted.
 */
int	check_sorted(t_stack **pile_a)
{
	t_stack	*node;
	int		tmp;

	node = *pile_a;
	tmp = node->value;
	node = node->next;
	while (node)
	{
		if (tmp > node->value)
			return (1);
		tmp = node->value;
		node = node->next;
	}
	return (0);
}

/**
 * @brief Finds the next minimum element in the stack that has not been ranked.
 *
 * This function iterates through the linked list representing the stack and 
 * identifies the element with the smallest value that has not yet been assigned 
 * a rank (indicated by a rank value of -1). It returns a pointer to this element.
 *
 * @param pile_a A double pointer to the head of the stack (linked list).
 *               The stack is represented as a linked list of t_stack nodes.
 *
 * @return A pointer to the t_stack node containing the next minimum value 
 *         that has not been ranked. If no such node exists, returns NULL.
 */
t_stack	*get_next_min(t_stack **pile_a)
{
	t_stack	*head;
	t_stack	*min;
	int		tmp;

	tmp = 0;
	min = NULL;
	head = *pile_a;
	while (head)
	{
		if (head->rank == -1 && (!tmp || head->value < min->value))
		{
			min = head;
			tmp = 1;
		}
		head = head->next;
	}
	return (min);
}

/**
 * @brief Assigns ranks and initializes additional properties for each node in the stack.
 *
 * This function iterates through the stack, assigning a unique rank to each node
 * based on the order of their values (from smallest to largest). It also initializes
 * the following properties for each node:
 * - `pos`: Set to -1, representing an uninitialized position.
 * - `target`: Set to -1, representing an uninitialized target.
 * - `cost_a`: Set to -1, representing an uninitialized cost for stack A.
 * - `cost_b`: Set to -1, representing an uninitialized cost for stack B.
 *
 * The function uses `get_next_min` to retrieve the next node with the smallest value
 * in the stack that has not yet been ranked.
 *
 * @param pile A double pointer to the stack (`t_stack **pile`) to be indexed.
 */
void	index_pile(t_stack **pile)
{
	t_stack	*node;
	int		index;

	index = 0;
	node = get_next_min(pile);
	while (node)
	{
		node->rank = index++;
		node->pos = -1;
		node->target = -1;
		node->cost_a = -1;
		node->cost_b = -1;
		node = get_next_min(pile);
	}
}

/**
 * @brief Initializes a stack (pile_a) with values from the given array of strings (av).
 * 
 * This function iterates through the array of strings (av), converts each string
 * to an integer using `ft_atoi`, creates a new stack node with the integer value,
 * and adds the node to the end of the stack (pile_a). After populating the stack,
 * it assigns an index to each element in the stack using the `index_pile` function.
 * 
 * @param pile_a A pointer to the pointer of the stack to be initialized.
 * @param av An array of strings containing the values to populate the stack.
 */
void	init_stack(t_stack **pile_a, char **av)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (av[i])
	{
		new = lstnew(ft_atoi(av[i]));
		lstadd_back(pile_a, new);
		i++;
	}
	index_pile(pile_a);
}
