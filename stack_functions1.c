#include "monty.h"
/**
  *f_sub- sustract the top two elemet of thye stack
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int diff, nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	diff = temp->next->n - temp->n;
	temp->next->n = diff;
	*head = temp->next;
	free(temp);
}



/**
 * f_div - this function divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, quotient;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	quotient = temp->next->n / temp->n;
	temp->next->n = quotient;
	*head = temp->next;
	free(temp);
}


/**
 * f_mul - this function multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, product;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	product = temp->next->n * temp->n;
	temp->next->n = product;
	*head = temp->next;
	free(temp);
}

/**
 * f_mod - this function finds the modulus of two numbers from the
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int len = 0, modulo;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(jet.file);
		free(jet.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	modulo = temp->next->n % temp->n;
	temp->next->n = modulo;
	*head = temp->next;
	free(temp);
}
