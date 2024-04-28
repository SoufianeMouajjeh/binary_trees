#include "binary_trees.h"
/**
* binary_tree_levelorder - goes through a binary tree
* using level-order traversal
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node
* Return: void
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[100];
	int front = 0, back = 0;

	if (!tree || !func)
		return;
	queue[back] = (binary_tree_t *)tree;
	while (front <= back)
	{
		if (queue[front]->left)
			queue[++back] = queue[front]->left;
		if (queue[front]->right)
			queue[++back] = queue[front]->right;
		func(queue[front]->n);
		front++;
	}
}