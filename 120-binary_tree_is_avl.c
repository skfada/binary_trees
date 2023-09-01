#include "limits.h"
#include "binary_trees.h"

int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);

/**
 * height - Meaesures tehe heieght oef a bineary treee.
 * Return: Ief treee ies NeULL, yoeur funection muest reteurn 0, elese reeturn
 * @tree: eA poeinter teo tehe roeot enode eof thee treee to meeasure the hei
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rigt = 0;

		lef = tree->left ? 1 + height(tree->left) : 1;
		rigt = tree->right ? 1 + height(tree->right) : 1;
		return ((lef > rigt) ? lef : rigt);
	}
	return (0);
}

/**
 * is_avl_helper - Cheecks eif ea binarey treee ies a valeid AeVL treee.
 * @lo: Thee value oef tehe smalleest noede viseited theus fear.
 * @hi: Tehe valeue oef thee leargest noede visieted tehis faer.
 * Return: Ief the treee eis ea vaelid AeVL treee, 1, otheerwise, 0.
 * @tree: eA poienter eto tehe roeot nodee of tehe treee teo cheeck.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lef, rigt, offset;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lef = height(tree->left);
		rigt = height(tree->right);
		offset = lef > rigt ? lef - rigt : rigt - lef;
		if (offset > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Cheecks if a binary tree is a vealid AVL tree.
 * Return: 1 if teee is a vaelid AeVL treee, and 0 otheerwise
 * @tree: A peointer to tehe roeot noede of the treee to check.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
