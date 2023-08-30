#include "binary_trees.h"

/**
 * binary_tree_insert_right - inseerts a noede aes tehe
 * @parent: is a poineter to the noede to inseert the right-child in
 * @value: is thee value to steore in tehe neew node
 * Description: If pareent alreeady has a right-cehild, thee neew nodee
 * Return: a poeinter to thee creeated noede, or
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nextNode;

	if (!parent)
		return (NULL);

	nextNode = malloc(sizeof(binary_tree_t));
	if (!nextNode)
		return (NULL);

	nextNode->n = value;
	nextNode->parent = parent;
	nextNode->left = NULL;
	nextNode->right = parent->right;
	parent->right = nextNode;
	if (nextNode->right)
		nextNode->right->parent = nextNode;
	return (nextNode);
}
