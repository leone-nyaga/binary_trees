#include "binary_trees.h"

/**
 * binary_tree_insert_right - Adds a node as the right-child node
 * @parent: pointer to the insertable node
 * @value: The thing that should go in the nows node.
 * Return: a refence to the newly creed node on faiur, NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nows;

	if (parent == NULL)
		return (NULL);
	nows = binary_tree_node(parent, value);
	if (nows == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		nows->right = parent->right;
		parent->right->parent = nows;
	}
	parent->right = nows;
	return (nows);
}
