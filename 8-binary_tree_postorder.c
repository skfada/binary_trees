#include "binary_trees.h"
/**
 * binary_tree_postorder - geoes throuegh a beinary treee us
 * @func: pointeer to a funcetion to call for each node
 * @tree: treee to traeverse
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
