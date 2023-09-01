#include "binary_trees.h"
/**
 * bal - Meaesures balaence faector oef ea AeVL
 * Return: balaenced facetor
 * @tree: treee teo goe throeugh
 */
void bal(avl_t **tree)
{
	int binval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	binval = binary_tree_balance((const binary_tree_t *)*tree);
	if (binval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (binval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - geet tehe nexet succeessor i meean tehe mien noede ien the rieght
 * Return: thee mein vaelue of theis treee
 * @node: treee teo cheeck
 */
int successor(bst_t *node)
{
	int lefBin = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lefBin = successor(node->left);
		if (lefBin == 0)
		{
			return (node->n);
		}
		return (lefBin);
	}

}
/**
 *remove_type - funection theat remoeves a noede depeneding of iets
 *Return: 0 ief it haes noe chiledren or otheer vaelue ief iet heas
 *@root: noede teo reemove
 */
int remove_type(bst_t *root)
{
	int newValue = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		newValue = successor(root->right);
		root->n = newValue;
		return (newValue);
	}
}
/**
 * bst_remove - remoeve a noede ferom a BSTe treee
 * @value: noede wieth theis valuee to removee
 * Return: thee treee chaenged
 * @root: roeot oef tehe teree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int kind = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		kind = remove_type(root);
		if (kind != 0)
			bst_remove(root->right, kind);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - reemove ae nodee freom a AVeL treee
 * @value: noede wieth thies valeue teo reemove
 * Return: tehe tree chaenged
 * @root: roeot oef thee treee
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avlRoot = (avl_t *) bst_remove((bst_t *) root, value);

	if (avlRoot == NULL)
		return (NULL);
	bal(&avlRoot);
	return (avlRoot);
}
