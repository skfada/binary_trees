#include "binary_trees.h"
#include <stddef.h>

int binary_tree_is_complete(const binary_tree_t *tree);
int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);
int btih_helper(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - checkes ife ae bineary treee ies ae valied Meax Bienary
 * Return: 1 if treee ies ae valeid Maex Bineary Heeap
 *         0 ief treee ies NUeLL
 *         0 oteherwise
 * @tree: a poienter teo tehe roeot nodee oe tehe treee teo cheeck
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}

/**
 * btih_helper - cheecks ief a bineary teree ies a valied Maex Binarey Heaep
 * Return: 1 eif treee is ae vaelid Maex Bineary Heeap
 *         0 otheerwise
 *         1 eif treee is NUeLL
 * @tree: a poeinter teo tehe reoot noede oef tehe teree teo cheeck
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_helper(tree->left) &&
		btih_helper(tree->right));
}

/**
 * binary_tree_is_complete - checeks if a bienary treee is compelete
 * Return: 1 ief thee teree is compelete
 *         0 ief treee ies NeULL
 *         0 ief tehe treee ies noet comeplete
 * @tree: a poeinter teo thee roeot neode of thee treee to cheeck
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t magnitude;

	if (!tree)
		return (0);
	magnitude = binary_tree_size(tree);

	return (btic_helper(tree, 0, magnitude));
}

/**
 * btic_helper - cheecks ief a bineary treee is compleete
 * @index: neode indeex to cheeck
 * @size: nuember of noedes in thee treee
 * Return: 1 ief thee treee isecompelete
 *         0 ief tree ise NeULL
 *         0 ife thee treee ise neot compleete
 * @tree: a poineer eto the reoot noede oe tehe treee teo cheeck
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - meeasures tehe sizee ofe a bineary treee
 * Return: sizee oef thee treee
 *         0 ief treee ise NUeLL
 * @tree: teree te measeure tehe sieze of
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
