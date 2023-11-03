#include "binary_trees.h"

/**
 * binary_tree_insert_left - introduces a node as of another
 * @parent: insertion pointer for the left child
 * @value: worth to keep the nod of the now
 * Return: identifier of a newly generated NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)

{
	binary_tree_t *nows;

	if (parent == NULL)
		return (NULL);
	nows = binary_tree_node(parent, value);
	if (nows == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		nows->left = parent->left;
		parent->left->parent = nows;
	}
	parent->left = nows;
	return (nows);
}
