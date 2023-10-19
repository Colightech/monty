#include "monty.h"
/**
 * f_push - add an element to the stack
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, x = 0, flag = 0;

	if (jet.arg)
	{
		if (jet.arg[0] == '-')
			x++;
		for (; jet.arg[x] != '\0'; x++)
		{
			if (jet.arg[x] > 57 || jet.arg[x] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(jet.file);
			free(jet.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(jet.arg);
	if (jet.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * f_pall - prints all elements of the stack
 * @head: stack head
 * @counter: void
 * Return: void
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void)counter;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * f_pint - this function prints the top
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * f_pop - this function delete element from the stack
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * f_swap - swap the fisrt top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, copy;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	copy = temp->n;
	temp->n = temp->next->n;
	temp->next->n = copy;
}

/**
 * f_add - function taht adds the
 *top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, sum;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*head = temp->next;
	free(temp);
}

/**
  *f_nop- does nothing
  *@head: stack head
  *@counter: line_number
  *Return: void
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
