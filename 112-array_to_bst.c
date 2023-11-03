#include "binary_trees.h"

/**
 * array_to_bst - Creates a Binary Search Tree from an array.
 * @array: A pointer to the first element of the array to be transformed.
 * @size: The number of elements in the array.
 * Return: A pointer to the root node of the generated BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *tree = NULL;
    size_t index = 0;

    if (array == NULL)
        return (NULL);

    while (index < size)
    {
        size_t inner_index = 0;

        while (inner_index < index)
        {
            if (array[inner_index] == array[index])
                break;

            inner_index++;
        }

        if (inner_index == index)
        {
            if (bst_insert(&tree, array[index]) == NULL)
                return (NULL);
        }

        index++;
    }

    return (tree);
}

