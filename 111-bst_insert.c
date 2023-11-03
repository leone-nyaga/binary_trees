#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a binary search tree.
 * @tree: A double pointer to the root of the BST.
 * @value: The value to be inserted.
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *current_node, *new_node;

    if (tree == NULL)
        return (NULL);

    current_node = *tree;

    if (current_node == NULL)
    {
        new_node = binary_tree_node(current_node, value);

        if (new_node == NULL)
            return (NULL);

        return (*tree = new_node);
    }

    if (value < current_node->n)
    {
        if (current_node->left != NULL)
            return bst_insert(&(current_node->left), value);

        new_node = binary_tree_node(current_node, value);

        if (new_node == NULL)
            return (NULL);

        return (current_node->left = new_node);
    }

    if (value > current_node->n)
    {
        if (current_node->right != NULL)
            return bst_insert(&(current_node->right), value);

        new_node = binary_tree_node(current_node, value);

        if (new_node == NULL)
            return (NULL);

        return (current_node->right = new_node);
    }

    return (NULL);
}

