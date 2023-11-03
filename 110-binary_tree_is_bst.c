#include "binary_trees.h"

int is_bst_helper(const binary_tree_t *tree, int min_value, int max_value);

/**
 * binary_tree_is_bst - Verify if a binary tree is a Binary Search Tree (BST).
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if it's a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return is_bst_helper(tree, INT_MIN, INT_MAX);
}

/**
 * is_bst_helper - Check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree.
 * @min_value: The minimum value that a node can have.
 * @max_value: The maximum value that a node can have.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int min_value, int max_value)
{
    if (tree != NULL)
    {
        if (tree->n < min_value || tree->n > max_value)
            return (0);

        return (is_bst_helper(tree->left, min_value, tree->n - 1) &&
                is_bst_helper(tree->right, tree->n + 1, max_value));
    }

    return (1);
}

