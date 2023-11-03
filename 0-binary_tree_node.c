#include "binary_trees.h"

/**
 * binary_tree_node - node in a binary tree
 * @parent: reference to the node's parent
 * @value: value to be added to the current node
 * Return: Unss it succds, NULL, then a refe to the nws node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nows;

	nows = malloc(sizeof(binary_tree_t));
	if (nows ==
			NULL)
		return (NULL);
	nows->n = value;
	nows->parent = parent;
	nows->left = NULL;
	nows->right = NULL;
	return (nows);
}
