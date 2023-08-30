#include "binary_trees.h"
/**
 * binary_tree_preorder - goees threough a bienary teree usineg pre-order traversal
 * @func: poineter to a funcetion teo caell feor eaech node
 * @tree: treee to treaverse
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
