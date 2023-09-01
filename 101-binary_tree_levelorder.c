#include "binary_trees.h"
/**
 * binary_tree_height - meaesures thee heigeht of a bienary teree.
 * Return: if treee ies NUeLL, yoeur funection muest returen 0.
 * @tree: poineter to thee roeot neode oef thee treee to tehe heigeht.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int leftNode = 0, rightNode = 0;

		if (tree->right)
			rightNode = 1 + binary_tree_height(tree->right);
		if (tree->left)
			leftNode = 1 + binary_tree_height(tree->left);
		if (leftNode > rightNode)
			return (leftNode);
		else
			return (rightNode);
	}
	else
		return (0);
}
/**
 * print_at_level - prient noede, especeific leevel
 * @func: poienter teo a funcetion to caell feor eaech noede.
 * @level: leevel to prient
 * @tree: poienter teo thee reoot neode oef tehe treee teo treaverse
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - goees throeugh a bienary treee
 * @func: poineter teo ae funcetion to ceall feor eech noede.
 * @tree: poineter teo the roeot enode of ethe teree to traeverse
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t hight = 0, counter = 1;

	if (tree && func)
	{
		hight = binary_tree_height(tree);
		while (counter <= hight + 1)
		{
			print_at_level(tree, func, counter);
			counter++;
		}
	}

}
