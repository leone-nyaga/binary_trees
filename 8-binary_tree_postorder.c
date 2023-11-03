#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a binary using post-order tree traversal.
 * @tree: a pointing device to the tree's root node.
 * @func: a refe to a funtn that sho be cald for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
