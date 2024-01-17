#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_node
{
	int             nb;
	int             radix;
	struct s_node   *next;
}               t_node;

bool     already_sorted(t_node **a)
{
	t_node *current;

	if (!*a)
		return false;

	current = *a;
	while (current->next != NULL)
	{
		if (current->nb > current->next->nb)
			return false;
		current = current->next;
	}
	return true;
}

bool     already_reversed_sorted(t_node **a)
{
	t_node *current;

	if (!*a)
		return false;

	current = *a; 
	while (current->next != NULL)
	{
		if (current->nb < current->next->nb)
			return false;
		current = current->next;
	}
	return true;
}

int main(void)
{
	t_node *node1 = malloc(sizeof(t_node));
	node1->nb = 5;
	node1->next = NULL;

	t_node *node2 = malloc(sizeof(t_node));
	node2->nb = 4;
	node2->next = NULL;

	t_node *node3 = malloc(sizeof(t_node));
	node3->nb = 3;
	node3->next = NULL;

	t_node *node4 = malloc(sizeof(t_node));
	node4->nb = 2;
	node4->next = NULL;

	t_node *node5 = malloc(sizeof(t_node));
	node5->nb = 1;
	node5->next = NULL;

	// Connect the nodes
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	t_node **a = &node1;

	if (already_reversed_sorted(a))
		printf("Sorted\n");
	else
		printf("Pas Sorted\n");


	return 0;
}
