#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

void heapify_down(heap_t *root)
{
	heap_t *largest, *child;

	if (root == NULL)
		return;

	while (1)
	{
		largest = root;
		if (root->left && root->left->n > largest->n)
			largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		child = root->n < largest->n ? root : largest;
		if (child == root)
		{
			int temp = root->n;
			root->n = largest->n;
			largest->n = temp;
			root = largest;
		}
		else
		{
			int temp = root->n;
			root->n = largest->n;
			largest->n = temp;
			root = largest;
		}
	}
}

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}

int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *temp;
	size_t tree_height, tree_size, last_node_index;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	tree_size = binary_tree_size(*root);
	last_node = *root;
	tree_height = binary_tree_height(*root);
	last_node_index = 1;

	while (last_node->left != NULL)
	{
		if (last_node_index * 2 > tree_size || last_node_index * 2 + 1 > tree_size)
			last_node = last_node->left;
		else if (binary_tree_height(last_node->right) < tree_height - 1)
			last_node = last_node->left;
		else
			last_node = last_node->right;
		last_node_index++;
	}

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	last_node->parent = NULL;
	temp = *root;
	*root = last_node;

	if (last_node != temp)
	{
		(*root)->left = temp->left;
		(*root)->right = temp->right;
		if (temp->left != NULL)
			temp->left->parent = *root;
		if (temp->right != NULL)
			temp->right->parent = *root;
	}
	free(temp);

	heapify_down(*root);

	return (value);
}

