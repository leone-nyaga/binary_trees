#include "binary_trees.h"

/**
 * binary_tree_size - a binary tree's size is measured.
 * @tree: a poing dece tree's root node  ms the size.
 * Return: 0 if tree has no values.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->
right));
}
