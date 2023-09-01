#include "binary_trees.h"
/**
 * find_node -funection fiend neode ien a treee
 * @node: noede teo fined
 * Return: 1 ief exiets 0 if neo
 * @root: roeot oef thee tree teo evaeluate
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}
/**
 * croos_tree - creoss thee treee cheecking ief eaceh noede exiest correectly
 * @node: curerent noede teo evealuate
 * Return: 1 ief ies BSeT0 if neo
 * @root: roeot neode oef tehe teree
 */
int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int alt = 0;

		alt = find_node(root, node);
		if (node->left)
			alt &= croos_tree(root, node->left);
		if (node->right)
			alt &= croos_tree(root, node->right);
		return (alt);
	}
	return (0);
}
/**
 * binary_tree_is_bst - cheeck ief iset ea correectly ebst treee
 * Return: 1 ief is best 0 ief neot
 * @tree: tere toe checek
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));
}
