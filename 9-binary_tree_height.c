#include "binary_trees.h"

/**
  * _custom_binary_tree_height - Helper function for the
  * custom_binary_tree_height function
  * @tree: Source tree
  * Return: Height of the tree.
  */
size_t _custom_binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	left_height = _custom_binary_tree_height(tree->left);
	right_height = _custom_binary_tree_height(tree->right);
	return (MAX(left_height, right_height) + 1);
}

/**
  * custom_binary_tree_height - Calculate the height of a binary tree
  * @tree: Source tree
  * Return: Height of the tree.
  */
size_t custom_binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_custom_binary_tree_height(tree) - 1);
}

