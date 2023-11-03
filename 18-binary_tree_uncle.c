#include "binary_trees.h"

/**
 * binary_tree_sibling - detects a node's sibling
 *@node: reference to the node where the sibling is located
 * Return: else a reference to the sibling node NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node == node->parent->right)
		return (node->parent->left);
	return (node->parent->right);
}

/**
 *binary_tree_uncle - detects the node's uncle
 *@node: arrow pointing to the uncle's node
 * Return: if NULL, reference to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
