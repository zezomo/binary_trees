#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_noded;

	new_noded = malloc(sizeof(binary_tree_t));

	if (new_noded == NULL)
		return (NULL);
	new_noded->n = value;
	new_noded->parent = parent;
	new_noded->left = NULL;
	new_noded->right = NULL;
	return (new_noded);
}
