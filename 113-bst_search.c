#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST for searching.
 * @value: The value to search for in the tree.
 * Return: A node pointer with a value equal to 'value'.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return (NULL);

    if (tree->n == value)
        return ((void *)tree);

    if (tree->n > value)
        return bst_search(tree->left, value);

    if (tree->n < value)
        return bst_search(tree->right, value);

    return (NULL);
}

