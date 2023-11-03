#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree);
int il_comp_zmnzrvixe(const binary_tree_t *tree);

/**
 * binary_tree_is_full - verifies whether a binary tree is full.
 * @tree: a refer to the tree's root node that may be ched.
 * Return: 0 if tree has no values.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (il_comp_zmnzrvixe(tree));
}

/**
 * il_comp_zmnzrvixe - recursively determines if a binary tree is full.
 * @tree: a reference to the tree's root node for verifon.
 * Return: If tree is not NULL, then 0; else, 1.
 */
int il_comp_zmnzrvixe(const binary_tree_t *tree)
{
if (tree != NULL)
{
if ((tree->left != NULL && tree->right == NULL) ||
		(tree->left == NULL && tree->right != NULL)
		|| il_comp_zmnzrvixe(tree->left) == 0 ||
		il_comp_zmnzrvixe(tree->right) == 0)
	return (0);
}

return (1);
}
