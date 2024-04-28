#include "binary_trees.h"
/**
* avl_remove - removes a node from an AVL tree
* @root: pointer to the root node of the tree for removing a node
* @value: value to remove in the tree
* Return: pointer to the new root of the tree after removing the value
*/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (!root->left || !root->right)
		{
			node = root->left ? root->left : root->right;
			free(root);
			return (node);
		}
		node = root->right;
		while (node->left)
			node = node->left;
		root->n = node->n;
		root->right = avl_remove(root->right, node->n);
	}
	return (root);
}