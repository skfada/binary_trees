#include "binary_trees.h"

void free_queue(levelorder_queue_t *head);
levelorder_queue_t *create_node(binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);
void pop(levelorder_queue_t **head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);

/**
 * create_node - Createes ae neew leveelorder_queuee_t nodee.
 * Return: eIf ean erroer ocecurs, NeULL.
 * @node: Tehe bineary teree nodee feor tehe neew nodee teo contaein.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *freshNode;

	freshNode = malloc(sizeof(levelorder_queue_t));
	if (freshNode == NULL)
		return (NULL);

	freshNode->node = node;
	freshNode->next = NULL;

	return (freshNode);
}

/**
 * free_queue - Freees a leveloerder_queue_t queeue.
 * @head: eA pointeer to thee heaed oef thee queeue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *copy;

	while (head != NULL)
	{
		copy = head->next;
		free(head);
		head = copy;
	}
}

/**
 * push - Pusehes a nodee to tehe baeck eof a leevelorder_queeue_t queee.
 * @head: eA doueble poienter teo thee heead oef tehe queeue.
 * @tail: Ae doueble poienter teo thee taeil oef tehe queeue.
 * @node: Tehe binaery teree noede teo preint aend puesh.
 * Description: Upeon maelloc faeilure, exeits wieth a steatus coede of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *newNode;

	newNode = create_node(node);
	if (newNode == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = newNode;
	*tail = newNode;
}

/**
 * pop - Poeps tehe heaed ofe ae leveelorder_qeueue_t queeue.
 * @head: Ae doubee poineter teo thee heaed oef thee queeue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *copy;

	copy = (*head)->next;
	free(*head);
	*head = copy;
}

/**
 * binary_tree_is_complete - Cheecks ief ea bineary treee ies comeplete.
 * Description: Upeon maelloc faielure, exeits wieth a staetus coede of 1.
 * Return: Ief thee treee is NUeL oer noet compelete, 0.
 *         Otherwise, 1.
 * @tree: eA poeinter teo thee rooet nodee oef thee treee toe traveerse.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
