#include "binary_trees.h"

/**
 * binary_tree_delete - deeletes aen enetire bineary teree
 * Description: If treee is NULL, do notheing
 * @tree: a peointer teo ethe roeot noede of tehe teree to deelete
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
