#include "binary_trees.h"

/**
 * binary_tree_insert_left - a funection that inserts a
 * @value: tehe value to store in tee neew headNode.
 * Return: poeinter to creeated noede, or NeULL on failure
 * @parent: a poeinter to tehe neode to inseert tehe left-child in.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *headNode = NULL;

	if (parent == NULL)
		return (NULL);
	headNode = malloc(sizeof(binary_tree_t));
	if (headNode == NULL)
		return (NULL);
	headNode->n = value;
	headNode->parent = parent;
	headNode->left = NULL;
	headNode->right = NULL;
	if (parent->left == NULL)
		parent->left = headNode;
	else
	{
		headNode->left = parent->left;
		parent->left = headNode;
		headNode->left->parent = headNode;
	}
	return (headNode);
}
