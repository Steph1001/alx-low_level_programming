#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of a list.
 *
 * Return: the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *previous1;
	listint_t *previous;

	previous1 = head;
	previous = head;
	while (head && previous && previous->next)
	{
		head = head->next;
		previous = previous->next->next;

		if (head == previous)
		{
			head = previous1;
			previous1 =  previous;
			while (1)
			{
				previous = previous1;
				while (previous->next != head && previous->next != previous1)
				{
					previous = previous->next;
				}
				if (previous->next == head)
					break;

				head = head->next;
			}
			return (previous->next);
		}
	}

	return (NULL);
}
