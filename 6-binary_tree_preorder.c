#include "binary_trees.h"

/**
 * binary_tree_preorder - using a binary tree, oes
 * @tree: pointer to the tree's root node
 * @func:  pointer to a fuco tat will be cad aer eah nod
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
