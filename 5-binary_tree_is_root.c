#include "binary_trees.h"

/**
 * binary_tree_is_root - determines if a certain node is active
 * @node: an indication of the node
 * Return: if node is the root, 1
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
