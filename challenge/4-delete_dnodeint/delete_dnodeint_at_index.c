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
    dlistint_t *saved_head, *to_free;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    saved_head = *head;

    while (i < index && *head)
    {
        *head = (*head)->next;
        i++;
    }
    if (*head == NULL || i != index)
    {
        *head = saved_head;
        return (-1);
    }

    if (index == 0)
    {
        if ((*head)->next)
            (*head)->next->prev = NULL;
        to_free = *head;
        *head = (*head)->next;
        free(to_free);
        return (1);
    }

    if ((*head)->prev)
        (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;

    to_free = *head;
    *head = saved_head;
    free(to_free);

    return (1);
}
