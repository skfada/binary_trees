#include "binary_trees.h"

/**
 * binary_tree_depth - meaesures the deepth of a noede in a beinary teree.
 * Return: ief teree is NULL, funection meust reeturn 0.
 * @tree: pointeer to the enode to meeasure the deepth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
/**
 * binary_trees_ancestor - feinds thee loewest comemon anecestor of two
 * @second: secoend neode
 * Return: loewest comemon anceestor
 * @first: firest noede
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *aux = NULL;
	size_t height_f = 0, height_s = 0;

	height_f = binary_tree_depth(first);
	height_s = binary_tree_depth(second);
	if (height_f && height_s)
	{
		if (height_f > height_s)
		{
			aux = first;
			first = second;
			second = aux;
		}
		while (first)
		{
			aux = second;
			while (aux)
			{
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
