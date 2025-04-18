/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:03:18 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 02:19:23 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

/**
 * @brief Calculates the size of a linked list of type t_stack.
 * 
 * This function traverses through the linked list starting from the head node
 * and counts the number of nodes in the list.
 * 
 * @param lst A double pointer to the head of the linked list of type t_stack.
 * 
 * @return The total number of nodes in the linked list.
 */
int	lst_size(t_stack **lst)
{
	t_stack	*node;
	int		count;

	node = *lst;
	count = 0;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}

/**
 * @brief Retrieves the last element of a linked list of type t_stack.
 * 
 * This function traverses the linked list starting from the given node
 * and returns a pointer to the last node in the list. If the input list
 * is NULL, the function returns NULL.
 * 
 * @param lst A pointer to the first node of the linked list.
 * 
 * @return A pointer to the last node of the linked list, or NULL if the
 *         input list is empty.
 */
t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Adds a new element to the end of a linked list.
 * 
 * This function appends a new node to the end of a linked list of type `t_stack`.
 * If the list is empty, the new node becomes the first element of the list.
 * 
 * @param lst A double pointer to the head of the linked list.
 *            If the list is empty, this pointer will be updated to point to the new node.
 * @param new A pointer to the new node to be added to the list.
 *            This node should be properly initialized before calling the function.
 * 
 * @note If either `lst` or `new` is NULL, the function does nothing.
 */
void	lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		lstlast(*lst)->next = new;
	else
		*lst = new;
}

/**
 * @brief Creates a new node for a stack.
 * 
 * This function allocates memory for a new stack node of type `t_stack`,
 * initializes its `value` field with the given content, sets its `rank` 
 * field to -1, and its `next` pointer to NULL.
 * 
 * @param content The integer value to be stored in the new stack node.
 * 
 * @return A pointer to the newly created stack node, or NULL if memory 
 * allocation fails.
 */
t_stack	*lstnew(int content)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->value = content;
	lst->rank = -1;
	lst->next = NULL;
	return (lst);
}
