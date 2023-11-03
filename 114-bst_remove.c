#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_find_and_remove(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *find_inorder_successor(bst_t root);

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed from the tree.
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return bst_find_and_remove(root, root, value);
}

/**
 * bst_find_and_remove - Recursively removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A BST pointer pointing to the current node.
 * @value: The target value to remove.
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_find_and_remove(bst_t *root, bst_t *node, int value)
{
    if (node != NULL)
    {
        if (node->n == value)
            return bst_delete(root, node);

        if (node->n > value)
            return bst_find_and_remove(root, node->left, value);

        return bst_find_and_remove(root, node->right, value);
    }
    return root;
}

/**
 * bst_delete - Removes a node from a binary search tree.
 * @root: A pointer to the BST's root node.
 * @node: A pointer to the node to be removed.
 * Return: A pointer to the new root node after removal.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
    bst_t *parent = node->parent;
    bst_t *successor = NULL;
    bst_t *new_root = NULL;

    if (node->left == NULL)
    {
        if (parent != NULL && parent->left == node)
            parent->left = node->right;
        else if (parent != NULL)
            parent->right = node->right;

        if (node->right != NULL)
            node->right->parent = parent;

        new_root = (parent == NULL ? node->right : root);
        free(node);
        return new_root;
    }

    if (node->right == NULL)
    {
        if (parent != NULL && parent->left == node)
            parent->left = node->left;
        else if (parent != NULL)
            parent->right = node->left;

        if (node->left != NULL)
            node->left->parent = parent;

        new_root = (parent == NULL ? node->left : root);
        free(node);
        return new_root;
    }

    successor = find_inorder_successor(node->right);
    node->n = successor->n;

    return bst_delete(root, successor);
}

/**
 * find_inorder_successor - Returns the minimum value in a binary search tree.
 * @root: A pointer to the root node of the BST for searching.
 * Return: The tree's smallest value.
 */
bst_t *find_inorder_successor(bst_t root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

