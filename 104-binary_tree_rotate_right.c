#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right.
 * @tree: A pointer to the root node of the tree.
 * Return: A pointer to the new root node after the rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root, *temp_parent;

    if (tree == NULL || tree->left == NULL)
        return (NULL);

    new_root = tree->left;
    temp_parent = new_root->right;
    new_root->right = tree;
    tree->left = temp_parent;

    if (temp_parent != NULL)
        temp_parent->parent = tree;

    temp_parent = tree->parent;
    tree->parent = new_root;
    new_root->parent = temp_parent;

    if (temp_parent != NULL)
    {
        if (temp_parent->left == tree)
            temp_parent->left = new_root;
        else
            temp_parent->right = new_root;
    }

    return new_root;
}

