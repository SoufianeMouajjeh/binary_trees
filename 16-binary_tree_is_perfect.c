#include "binary_trees.h"
/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* Return: 1 if perfect, 0 if not or if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right);
	if (left_height == right_height)
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
/**
* binary_tree_height - measures the height of a binary tree
* @tree: pointer to the root node of the tree to measure the height
* Return: height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}