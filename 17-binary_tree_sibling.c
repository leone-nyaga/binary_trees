#include "binary_trees.h"

/**
 * binary_tree_sibling - finds a node's sibling.
 * @node: a pointing device to the sibling node.
 * Return: If the pa,node,  node's si  all NULL, the va wi be NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (node->parent->left == node ? node->parent->right
			: node->parent->left);
}
