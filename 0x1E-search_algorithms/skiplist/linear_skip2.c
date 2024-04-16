#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/**
 * free_skiplist - Deallocates a singly linked list
 *
 * @list: Pointer to the linked list to be freed
 */
void free_skiplist(skiplist_t *list)
{
        skiplist_t *node;

        if (list)
        {
                node = list->next;
                free(list);
                free_skiplist(node);
        }
}

/**
 * init_express - Initializes the express lane of the linked list
 *
 * @list: Pointer to the head node of the list
 * @size: Number of nodes in the list
 */
void init_express(skiplist_t *list, size_t size)
{
        const size_t step = sqrt(size);
        size_t i;
        skiplist_t *save;

        for (save = list, i = 0; i < size; ++i, list = list->next)
        {
                if (i % step == 0)
                {
                        save->express = list;
                        save = list;
                }
        }
}

/**
 * create_skiplist - Create a single linked list
 *
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
        skiplist_t *list;
        skiplist_t *node;
        size_t save_size;

        list = NULL;
        save_size = size;
        while (array && size--)
        {
                node = malloc(sizeof(*node));
                if (!node)
                {
                        free_skiplist(list);
                        return (NULL);
                }
                node->n = array[size];
                node->index = size;
                node->express = NULL;
                node->next = list;
                list = node;
        }
        init_express(list, save_size);
        return (list);
}

/**
 * print_skiplist - dump the content of a skiplist_t
 *
 * @list: Pointer to the head of the list
 *
 * Return: void
 */
void print_skiplist(const skiplist_t *list)
{
        const skiplist_t *node;

        printf("List :\n");
        for (node = list; node; node = node->next)
        {
                printf("Index[%lu] = [%d]\n", node->index, node->n);
        }
        printf("\nExpress lane :\n");
        for (node = list; node; node = node->express)
        {
                printf("Index[%lu] = [%d]\n", node->index, node->n);
        }
        printf("\n");
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 * Return: A pointer on the first node where value is located, otherwise
 * NULL if value is not present in list or if head is NULL.
 *
 * Description: Assume that list will be sorted in ascending order.
 * Every time you compare a value in the list to the value you are
 * searching, you have to print this value.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *express_node;

	if (!list)
		return (NULL);
	node = express_node = list;
	while (express_node)
	{
		express_node = express_node->express;
		if (!express_node && (node->n < value && node->next))
		{
			express_node = node;
			while (express_node->next)
				express_node = express_node->next;
		}
		if (express_node->n >= value || express_node->next == NULL)
		{
			printf("Value checked at index [%ld] = [%d]\n", express_node->index, express_node->n);
			printf("Value found between indexes [%ld] and [%ld]\n", node->index, express_node->index);
			while (node->index <= express_node->index)
			{
				 printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
				 if (node->n == value)
					 return (node);
				 if (node == express_node)
					 return (NULL);
				 node = node->next;
			}
			return (NULL);
		}
		printf("Value checked at index [%ld] = [%d]\n", express_node->index, express_node->n);
		node = express_node;
	}
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	    skiplist_t *list, *res;

    	int array[] = {0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99};
    	size_t size = sizeof(array) / sizeof(array[0]);

    	list = create_skiplist(array, size);
    	print_skiplist(list);

    	res =  linear_skip(list, 53);
    	printf("Found %d at index: %lu\n\n", 53, res->index);
    	res =  linear_skip(list, 2);
    	printf("Found %d at index: %lu\n\n", 2, res->index);
    	res =  linear_skip(list, 999);
    	printf("Found %d at index: %p\n", 999, (void *) res);

    	free_skiplist(list);
    	return (EXIT_SUCCESS);
}
