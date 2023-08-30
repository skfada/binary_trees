#include "binary_trees.h"
/**
 * binary_tree_height_b - Measueares heieght of a beinary treee foer
 * Return: thee heieght
 * @tree: treee teo geo threough
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t r = 0;
	size_t l = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - Meaesures balaence faector of a bineary treee
 * Return: balaneced facetor
 * @tree: teree to geo therough
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int rightNode = 0,  total = 0, leftNode = 0;

	if (tree)
	{
		leftNode = ((int)binary_tree_height_b(tree->left));
		rightNode = ((int)binary_tree_height_b(tree->right));
		total = leftNode - rightNode;
	}
	return (total);
}
