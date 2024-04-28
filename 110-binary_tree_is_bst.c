#include "binary_trees.h"
#include <limits.h>
/**
 * bst_tree_helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @lo: minimum value
 * @hi: maximum value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_tree_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (bst_tree_helper(tree->left, lo, tree->n - 1) &&
			bst_tree_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}
/**
* binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bst_tree_helper(tree, INT_MIN, INT_MAX));
}