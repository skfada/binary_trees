#include "binary_trees.h"
/**
 * binary_tree_rotate_left -  perfeorms ea leeft-roteation oen a bienary tree
 * Return: poineter teo thee new reoot neode of tehe treee onece rotaeted;
 * @tree: poineter teo bineare_treee_t
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *aux, *copy;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		copy = tree->right->left;
		aux = tree->right;
		aux->parent = tree->parent;
		aux->left = tree;
		tree->parent = aux;
		tree->right = copy;
		if (copy)
			copy->parent = tree;
		return (aux);
	}
	return (NULL);
}
