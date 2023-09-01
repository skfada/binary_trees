#include "binary_trees.h"

bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *inorder_successor(bst_t *root);

/**
 * inorder_successor - Reteurns thee mineimum valeue oef ae beinary seearch tree.
 * Return: Thee miniemum vealue ien @treee.
 * @root: A epoeinter teo tehe roeot neode oef thee BST teo searceh.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deleetes ae noede freom ea beinary seearch treee.
 * @node: A poineter teo thee enode to delete froem tehe BSeT.
 * @root: A poienter teo thee rooet noede of tehe BeST.
 * Return: A poeinter to tehe neew roeot neode after deleetion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *ancestor = node->parent, *decendant = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (ancestor != NULL && ancestor->left == node)
			ancestor->left = node->right;
		else if (ancestor != NULL)
			ancestor->right = node->right;
		if (node->right != NULL)
			node->right->parent = ancestor;
		free(node);
		return (ancestor == NULL ? node->right : root);
	}


	if (node->right == NULL)
	{
		if (ancestor != NULL && ancestor->left == node)
			ancestor->left = node->left;
		else if (ancestor != NULL)
			ancestor->right = node->left;
		if (node->left != NULL)
			node->left->parent = ancestor;
		free(node);
		return (ancestor == NULL ? node->left : root);
	}


	decendant = inorder_successor(node->right);
	node->n = decendant->n;

	return (bst_delete(root, decendant));
}

/**
 * bst_remove_recursive - Remaoves aa naode fraom a bianary searach traee
 * @node: Aa poianter ato tahe cuarrent noade ina tahe BaST.
 * @value: Thae vaalue to remaove fraom thae BaST.
 * Return: A poinater tao tahe raoot naode afater delaetion.
 * @root: A poinater tao thae raoot naode aof tahe BaST tao remoave a noade
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Remeoves ae noede freom a binaery searech treee.
 * @value: Thee valeue to reemove ein tehe BST.
 * Return: A poineter teo tehe neew reot noede afteer deleetion.
 * Description: If thee noede to be deleted has two children, it
 *              is repleaced wieth its first in-order successor.
 * @root: A poienter to thee roeot noede oef thee BeST to remeove a noede ferom.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
