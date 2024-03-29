#include "binary_trees.h"

/**
 * is_full_and_same_level - Checks if a binary tree is full and all nodes
 *                          are at the same level.
 * @tree: Pointer to the root node of the tree to check.
 * @level: Level of the current node.
 *
 * Return: 1 if the tree is full and all nodes are at the same leve
 */
int is_full_and_same_level(const binary_tree_t *tree, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level);

	if (tree->left && tree->right)
	{
		int left_level = is_full_and_same_level(tree->left, level + 1);
		int right_level = is_full_and_same_level(tree->right, level + 1);

		if (left_level != 0 && right_level != 0 && left_level == right_level)
			return (left_level);
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
	if (tree == NULL)
		return (0);

	return (is_full_and_same_level(tree, 0) != 0);
}

