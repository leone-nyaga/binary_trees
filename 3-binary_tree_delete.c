#include "binary_trees.h"

/**
 * binary_tree_delete - completely removes
 * @tree: an indication of the root node
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
