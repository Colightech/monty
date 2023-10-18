#include "monty.h"

jet_t jet = {NULL, NULL, NULL, 0};

/**
* main - main function, where other function are connected.
* @argc: number of arguments
* @argv: arguement vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readInput = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	jet.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readInput > 0)
	{
		content = NULL;
		readInput = getline(&content, &size, file);
		jet.content = content;
		counter++;
		if (readInput > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
