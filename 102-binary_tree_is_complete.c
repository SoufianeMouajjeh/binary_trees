#include "binary_trees.h"
/**
* binary_tree_is_complete - checks if a binary tree is complete
* @tree: pointer to the root node of the tree to check
* Return: 1 if complete, 0 if not
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[100];
	int front = 0, back = 0;

	int flag = 0;

	if (!tree)
		return (0);
	queue[back] = (binary_tree_t *)tree;
	while (front <= back)
	{
		if (queue[front]->left)
		{
			if (flag)
				return (0);
			queue[++back] = queue[front]->left;
		}
		else
			flag = 1;
		if (queue[front]->right)
		{
			if (flag)
				return (0);
			queue[++back] = queue[front]->right;
		}
		else
			flag = 1;
		front++;
	}
	return (1);
}