#include "binary_trees.h"
/**
* bst_remove - removes a node from a Binary Search Tree
* @root: pointer to the root node of the tree where you will remove a node
* @value: value to remove in the tree
* Return: pointer to the new root node of the tree after removing the desired
* value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = root->right;
		while (tmp->left)
			tmp = tmp->left;
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}