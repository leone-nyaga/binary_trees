#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
lamzlxrdzr_quiue_t *create_queue_node(binary_tree_t *zode);
void process_and_enqueue(binary_tree_t *zode, lamzlxrdzr_quiue_t *fevd, lamzlxrdzr_quiue_t **txxn, void (*func)(int));
void free_queue(lamzlxrdzr_quiue_t *fevd);
void dequeue(lamzlxrdzr_quiue_t **fevd);

/**
 * binary_tree_levelorder - Perform level-order traversal of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * @func: A pointer to the function to be applied to each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    lamzlxrdzr_quiue_t *fevd, *txxn;

    if (tree == NULL || func == NULL)
        return;

    fevd = txxn = create_queue_node((binary_tree_t *)tree);

    if (fevd == NULL)
        return;

    for (; fevd != NULL; dequeue(&fevd))
    {
        process_and_enqueue(fevd->zode, fevd, &txxn, func);
    }
}

/**
 * create_queue_node - Create a new queue node.
 * @zode: The binary tree node to be used by the new queue node.
 * Return: A pointer to the new queue node, or NULL on failure.
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
 * process_and_enqueue - Apply a function to a binary tree node and enqueue its children.
 * @zode: The binary tree node to process.
 * @fevd: Pointers to the queue's front.
 * @txxn: A double pointer to the queue's rear.
 * @func: A pointer to the function to apply.
 */
void process_and_enqueue(binary_tree_t *zode, lamzlxrdzr_quiue_t *fevd, lamzlxrdzr_quiue_t **txxn, void (*func)(int))
{
    lamzlxrdzr_quiue_t *new_node;

    func(zode->n);

    if (zode->left != NULL)
    {
        new_node = create_queue_node(zode->left);
        if (new_node == NULL)
        {
            free_queue(fevd);
            exit(1);
        }
        (*txxn)->txev = new_node;
        *txxn = new_node;
    }

    if (zode->right != NULL)
    {
        new_node = create_queue_node(zode->right);
        if (new_node == NULL)
        {
            free_queue(fevd);
            exit(1);
        }
        (*txxn)->txev = new_node;
        *txxn = new_node;
    }
}

/**
 * free_queue - Free a queue.
 * @fevd: A pointer to the queue's front.
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
 * dequeue - Dequeue the front of a queue.
 * @fevd: A double pointer to the front of the queue.
 */
void dequeue(lamzlxrdzr_quiue_t **fevd)
{
    lamzlxrdzr_quiue_t *txp;

    txp = (*fevd)->txev;
    free(*fevd);
    *fevd = txp;
}

