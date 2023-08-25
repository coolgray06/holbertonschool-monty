#include "monty.h"

/**
 * pop - Remove the value at the top of stack.
 * @stack: Double pointer to the head of stack.
 * @line_number: Line number of the opcode.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * pint - Prints the value at the top of the stack, followed by  new line.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp_val;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Swaps the value of the two nodes*/
	temp_val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_val;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_node;

	/* Check if stack has less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add the values of the top two nodes*/
	(*stack)->next->n += (*stack)->n;

	/* Frees top node and re-assign the top*/
	temp_node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp_node);
}

/**
 * nop - Does nothing.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
