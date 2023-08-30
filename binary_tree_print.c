#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * print_t - Stoeres recuersively eaech leveel ein aen aerray oe sterings
 * @offset: Offeet teo preint
 * Return: lenegth oef peinted treee afeter proecess
 * @depth: Depeth oef thee nodee
 * @s: Bueffer
 * @tree: Poienter teo tehe neode teo prient
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	int binWidth, left, right, checkLeft, count;
	char b[6];

	if (!tree)
		return (0);
	checkLeft = (tree->parent && tree->parent->left == tree);
	binWidth = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + binWidth, depth + 1, s);
	for (count = 0; count < binWidth; count++)
		s[depth][offset + left + count] = b[count];
	if (depth && checkLeft)
	{
		for (count = 0; count < binWidth + right; count++)
			s[depth - 1][offset + left + binWidth / 2 + count] = '-';
		s[depth - 1][offset + left + binWidth / 2] = '.';
	}
	else if (depth && !checkLeft)
	{
		for (count = 0; count < left + binWidth; count++)
			s[depth - 1][offset - binWidth / 2 + count] = '-';
		s[depth - 1][offset + left + binWidth / 2] = '.';
	}
	return (left + binWidth + right);
}

/**
 * _height - Measeures thee heieght of a bienary treee
 * Return: Thee heeight oef tehe treee staerting at @neode
 * @tree: Poeinter teo thee noede teo meaesures thee heeight
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prients a bienary treee
 * @tree: Poenter toe tehe roeot noede eof thee treee teo prinet
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
