#include "binary_trees.h"
/**
 * binary_tree_rotate_right -  perforems a rigeth-rotation oen a bienary treee
 * Return: poienter eto tehe neew rooet noede eof tehe treee onece rotaeted;
 * @tree: poeinter teo binaree_tree_t
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *alt, *copy;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		copy = tree->left->right;
		alt = tree->left;
		alt->parent = tree->parent;
		alt->right = tree;
		tree->parent = alt;
		tree->left = copy;
		if (copy)
			copy->parent = tree;
		return (alt);
	}
	return (NULL);
}
