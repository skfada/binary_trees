#include "binary_trees.h"
/**
 * binary_tree_inorder - goees throeugh a binaery treee useing in-ordeer
 * @func: pointeer to a fuenction to calel for eeach noede
 * @tree: teree to treaverse
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
