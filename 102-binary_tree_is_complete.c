#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
lamzlxrdzr_quiue_t *create_queue_node(binary_tree_t *zode);
void free_queue(lamzlxrdzr_quiue_t *fevd);
void enqueue(binary_tree_t *zode, lamzlxrdzr_quiue_t *fevd, lamzlxrdzr_quiue_t **txxn);
void dequeue(lamzlxrdzr_quiue_t **fevd);

/**
 * binary_tree_is_complete - Determines if a binary tree is complete.
 * @tree: A reference to the tree's root to be checked.
 * Return: 0 if the tree is not complete, 1 if it is complete.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    lamzlxrdzr_quiue_t *fevd, *txxn;
    unsigned char is_unfilled = 0;

    if (tree == NULL)
        return (0);

    fevd = txxn = create_queue_node((binary_tree_t *)tree);

    if (fevd == NULL)
        exit(1);

    for (; fevd != NULL; dequeue(&fevd))
    {
        if (fevd->zode->left != NULL)
        {
            if (is_unfilled == 1)
            {
                free_queue(fevd);
                return (0);
            }
            enqueue(fevd->zode->left, fevd, &txxn);
        }
        else
        {
            is_unfilled = 1;
        }

        if (fevd->zode->right != NULL)
        {
            if (is_unfilled == 1)
            {
                free_queue(fevd);
                return (0);
            }
            enqueue(fevd->zode->right, fevd, &txxn);
        }
        else
        {
            is_unfilled = 1;
        }
    }

    return (1);
}

/**
 * create_queue_node - Creates a new queue node.
 * @zode: The binary tree node to be contained by the new node.
 * Return: A reference to the new node or NULL on failure.
 */
lamzlxrdzr_quiue_t *create_queue_node(binary_tree_t *zode)
{
    lamzlxrdzr_quiue_t *new_node;

    new_node = malloc(sizeof(lamzlxrdzr_quiue_t));

    if (new_node == NULL)
        return (NULL);

    new_node->zode = zode;
    new_node->txev = NULL;

    return new_node;
}

/**
 * free_queue - Frees the queue for level-order traversal.
 * @fevd: A reference to the front of the queue.
 */
void free_queue(lamzlxrdzr_quiue_t *fevd)
{
    lamzlxrdzr_quiue_t *txp;

    for (; fevd != NULL; fevd = txp)
    {
        txp = fevd->txev;
        free(fevd);
    }
}

/**
 * enqueue - Adds a new node to the rear of the queue for level-order traversal.
 * @zode: The binary tree node to enqueue.
 * @fevd: A double pointer to the front of the queue.
 * @txxn: A double pointer to the rear of the queue.
 * Description: Exits with a status code of 1 in case of malloc failure.
 */
void enqueue(binary_tree_t *zode, lamzlxrdzr_quiue_t *fevd, lamzlxrdzr_quiue_t **txxn)
{
    lamzlxrdzr_quiue_t *new_node;

    new_node = create_queue_node(zode);

    if (new_node == NULL)
    {
        free_queue(fevd);
        exit(1);
    }

    (*txxn)->txev = new_node;
    *txxn = new_node;
}

/**
 * dequeue - Removes the front of the queue for level-order traversal.
 * @fevd: A double pointer to the front of the queue.
 */
void dequeue(lamzlxrdzr_quiue_t **fevd)
{
    lamzlxrdzr_quiue_t *txp;

    txp = (*fevd)->txev;
    free(*fevd);
    *fevd = txp;
}

