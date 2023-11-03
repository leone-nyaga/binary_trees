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

/**
  * custom_binary_tree_size - Measure the size of a C binary tree
  * @tree: Input binary tree
  * Return: Number of descendant nodes.
  */
size_t custom_binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + custom_binary_tree_size(tree->left) +
			custom_binary_tree_size(tree->right));
}

/**
  * custom_binary_tree_is_perfect - Check if a C binary tree is perfect
  * @tree: Input binary tree
  * Return: 0 if false, 1 if true
  */
int custom_binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size, height;

	if (!tree)
		return (0);
	size = (int)custom_binary_tree_size(tree);
	height = custom_binary_tree_height(tree);
	return (size == (2 << height) - 1);
}
