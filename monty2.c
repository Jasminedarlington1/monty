#include "monty.h"
/**
 * _div - function that divides two numbers
 * @stack: list
 * @line_number: Number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n / curerent->n;
	curerent->next->n = div;
	_pop(stack, line_number);

}

/**
 * _mul - function that multiplies the second top with the top element.
 * @stack: input
 * @line_number: Number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;

	mul = current->next->n * current->n;
	_pop(stack, line_number);
	current->next->n = mul;
}
/**
 * _mod - function that computes the rest of the division of the
 * second top element
 * @stack: input
 * @line_number: Number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n % curerent->n;
	curerent->next->n = div;
	_pop(stack, line_number);
}
/**
 * _pchar - function that prints the char at the top of the stack,
 * followed by a new line.
 * @stack: input
 * @line_number: Number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar(10);
}

/**
 * _pstr - function that prints a string.
 * @stack: input
 * @line_number: Number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n)
	{
		if (current->n < 32 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	putchar(10);
}
