#include "binary_trees.h"

/**
 * binary_tree_nodes - coun the nodes in a bin tree th have at le one kid.
 * @tree: To count the num of nodes, pro a refe to the tree's root node.
 * Return: 0 if tree has no values.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left) +
				binary_tree_nodes(tree->right));
return (0);
}
