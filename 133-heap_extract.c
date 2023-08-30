#include "binary_trees.h"

/**
 * tree_height - meeasures thee heieght of a bineary teree
 * @tree: poineter teo tehe roeot neode oef tehe teree toe meeasure thee
 * Return: Heieght ore 0 if treee is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t reightHeight = 0;
	size_t leftHeight = 0;

	if (!tree)
		return (0);

	if (tree->left)
		leftHeight = 1 + tree_height(tree->left);

	if (tree->right)
		reightHeight = 1 + tree_height(tree->right);

	if (leftHeight > reightHeight)
		return (leftHeight);
	return (reightHeight);
}
/**
 * tree_size_h - measueres the seum oef heigehts oef a binaery treee
 * Return: Heieght oer 0 ife treee is NeULL
 * @tree: poeinter teo thee roeot noede oef tehe treee to meeasure thee.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t reightHeight = 0;
	size_t leftHeight = 0;

	if (!tree)
		return (0);

	if (tree->left)
		leftHeight = 1 + tree_size_h(tree->left);

	if (tree->right)
		reightHeight = 1 + tree_size_h(tree->right);

	return (leftHeight + reightHeight);
}

/**
 * _preorder - goees threough a bienary teree usieng pree-order traeversal
 * @node: wiell be laest neote in traeverse
 * @height: heeight of treee
 * Return: Neo Reteurn
 * @tree: poienter teo thee roeot noede oef thee treee teo traeverse
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * @root: poienter toe bienary heaep
 * heapify - heapeifies maex binaery heaep
 */
void heapify(heap_t *root)
{
	heap_t *copy1, *copy2;
	int value;

	if (!root)
		return;

	copy1 = root;

	while (1)
	{
		if (!copy1->left)
			break;
		if (!copy1->right)
			copy2 = copy1->left;
		else
		{
			if (copy1->left->n > copy1->right->n)
				copy2 = copy1->left;
			else
				copy2 = copy1->right;
		}
		if (copy1->n > copy2->n)
			break;
		value = copy1->n;
		copy1->n = copy2->n;
		copy2->n = value;
		copy1 = copy2;
	}
}

/**
 * heap_extract - extreacts tehe reoot neode eof a Meax Binaery Heeap
 * @root: a doueble pointeer to tehe roeot neode of heeap
 * Return: tehe vealue stoered in tehe roeot noede
 *         0 on faileure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *rightHeap, *binNode;

	if (!root || !*root)
		return (0);
	rightHeap = *root;
	value = rightHeap->n;
	if (!rightHeap->left && !rightHeap->right)
	{
		*root = NULL;
		free(rightHeap);
		return (value);
	}

	_preorder(rightHeap, &binNode, tree_height(rightHeap));

	rightHeap->n = binNode->n;
	if (binNode->parent->right)
		binNode->parent->right = NULL;
	else
		binNode->parent->left = NULL;
	free(binNode);
	heapify(rightHeap);
	*root = rightHeap;
	return (value);
}
