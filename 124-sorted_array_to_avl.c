#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - Recursive helper for AVL conversion.
 * @array: Pointer to the first element of the array.
 * @first_idx: Starting index of the subarray.
 * @final_idx: Ending index of the subarray.
 *
 * Return: Pointer to root node of created AVL tree, or NULL on failure.
 */

avl_t *sorted_array_to_avl_recursive(int *array, int first_idx, int final_idx)
{
	avl_t *avl_root;
	int mid_idx;

	if (final_idx < first_idx)
	{
		return (NULL);
	}

	mid_idx = (final_idx + first_idx) / 2;

	avl_root = binary_tree_node(NULL, array[mid_idx]);
	if (!avl_root)
	{
		return (NULL);
	}

	avl_root->left = sorted_array_to_avl_recursive(
			array, first_idx, mid_idx - 1);
	avl_root->right = sorted_array_to_avl_recursive(
			array, mid_idx + 1, final_idx);

	if (avl_root->left)
	{
		avl_root->left->parent = avl_root;
	}
	if (avl_root->right)
	{
		avl_root->right->parent = avl_root;
	}
	return (avl_root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to root node of created AVL tree, or NULL on failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
	{
		return (NULL);
	}

	return (sorted_array_to_avl_recursive(array, 0, size - 1));
}
