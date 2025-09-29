#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head, *node, *prev, *next;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    saved_head = *head;

    p = 0;
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }
    if (p != index || *head == NULL)
    {
        *head = saved_head;
        return (-1);
    }

    if (index == 0)
    {
        node = *head;
        next = node->next;
        free(node);
        *head = next;
        if (next)
            next->prev = NULL;
        return (1);
    }

    node = *head;
    prev = node->prev;
    next = node->next;


    if (prev)
        prev->next = next;

    if (next)
        next->prev = prev;

    free(node);

    *head = saved_head;

    return (1);
}
