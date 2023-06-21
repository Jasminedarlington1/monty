#include "monty.h"
/**
* free_stack - function that frees a doubly linked list
* @head: parameter
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
