#include "binary_trees.h"

/**
 * tree_is_perfect - function that checks if a tree is perfect or not
 * It has to have the same quantity of levels in left as right,
 * and each node has to have either 2 nodes or none.
 * @tree: tree to check
 * Return: 0 if it is not perfect, or the level of height if it is perfect
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);

	result = tree_is_perfect(tree);
	if (result > 0)
		return (1);

	return (0);
}

