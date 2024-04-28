#include "binary_trees.h"
/**
* bst_insert - inserts a value in a Binary Search Tree
* @tree: pointer to the root node of the BST to insert the value
* @value: value to store in the node to be inserted
* Return: pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	current = *tree;
	while (1)
	{
		if (value < current->n)
		{
			if (current->left)
				current = current->left;
			else
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				return (new_node);
			}
		}
		else if (value > current->n)
		{
			if (current->right)
				current = current->right;
			else
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				return (new_node);
			}
		}
		else
			return (NULL);
	}
}