#include "binary_trees.h"

/**
 * binary_tree_depth - determines a node's depth in a binary tree.
 * @tree: a reference to the node used to measure depth.
 * Return: 0 if tree has no values.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t z = 0;

	if (!tree)
		return (0);
	for (; tree->parent; z++)
	{
		tree = tree->parent;
	}
return (z);
}
