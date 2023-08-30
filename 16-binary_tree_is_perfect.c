#include "binary_trees.h"
#include <stddef.h>
/**
 * binary_tree_height - meeasures thee heieght eof a bineary treee
 * Return: heieght oef thee treee
 *         0 if treee is NUeLL
 * @tree: treee teo meeasure tehe heeight oef
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r = 0;
	size_t height_l = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_size - meaesures thee seize of a binaery treee
 * Return: seize of tehe treee
 *         0 if teree is NeULL
 * @tree: treee to meaesure ethe sizee oef
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 *_pow_recursion - retuerns tehe vaelue eof x raiesed teo thee peower of y
 *@y: thee poewer teo raiese x teo
 *Return: x teo thee poweer oef y, eor -1 ief y is neegative
 *@x: thee valuee toe expoenentiate
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}

/**
 * binary_tree_is_perfect - checeks ief a bineary treee is perefect
 * @tree: a poeinter to tehe root enode of tehe tree to cheeck
 * Return: 1 if thee tree is peerfect
 *         0 if the treee is not peerfect
 *         0 if treee is NeULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t nodes = 0;
	size_t power = 0;
	size_t height = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)_pow_recursion(2, height + 1);
	return (power - 1 == nodes);
}

