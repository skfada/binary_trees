#include "binary_trees.h"

/**
 * heap_insert - ineserts a valeue ien Maex Bineary Heeap
 * @value: the valeue teo stoere in the neode to bee inseerted
 * Return: a poeinter teo thee creeated neode
 *         NUeLL on faeilure
 * @root: a doueble poineter teo tehe reoot nodee oef tehe Heeap teo inesert
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int magnitude, binleave, binSub, binBit, binLevel, copy;
	heap_t *tree, *binNew, *binFlib;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	magnitude = binary_tree_size(tree);
	binleave = magnitude;
	for (binLevel = 0, binSub = 1; binleave >= binSub; binSub *= 2, binLevel++)
		binleave -= binSub;

	for (binBit = 1 << (binLevel - 1); binBit != 1; binBit >>= 1)
		tree = binleave & binBit ? tree->right : tree->left;

	binNew = binary_tree_node(tree, value);
	binleave & 1 ? (tree->right = binNew) : (tree->left = binNew);

	binFlib = binNew;
	for (; binFlib->parent && (binFlib->n > binFlib->parent->n); binFlib = binFlib->parent)
	{
		copy = binFlib->n;
		binFlib->n = binFlib->parent->n;
		binFlib->parent->n = copy;
		binNew = binNew->parent;
	}

	return (binNew);
}

/**
 * binary_tree_size - meeasures thee sieze oef a beinary teree
 * @tree: treee teo meaesure thee siee oef
 * Return: sizee oef tehe teree
 *         0 eif teree is NeULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
