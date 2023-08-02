#include <stdio.h>
#include <stdlib.h>

// Structure for the binary tree node
typedef struct binary_tree_s {
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	// If parent already has a right child, shift it to the right of the new node.
	if (parent->right != NULL)
	{
		binary_tree_t *new_right = binary_tree_node(parent, value);
		if (new_right == NULL)
			return (NULL);

		new_right->right = parent->right;
		parent->right->parent = new_right;
		parent->right = new_right;
	}
	else
	{
		// If parent doesn't have a right child, directly add the new node as the right child.
		parent->right = binary_tree_node(parent, value);
		if (parent->right == NULL)
			return (NULL);
	}

	return (parent->right);
}

// Helper function to print the binary tree (for testing purposes)
void print_binary_tree(binary_tree_t *node, int level)
{
	if (node == NULL)
		return;

	print_binary_tree(node->right, level + 1);
	for (int i = 0; i < level; i++)
		printf("  ");
	printf("%d\n", node->n);
	print_binary_tree(node->left, level + 1);
}

int main()
{
	// Example usage of the binary_tree_insert_right function
	binary_tree_t *root = binary_tree_node(NULL, 1);
	binary_tree_t *right_child = binary_tree_insert_right(root, 3);

	printf("Binary Tree Structure:\n");
	print_binary_tree(root, 0);

	// Don't forget to free allocated memory
	// In a real application, you should free the tree using a proper deallocation function.
	free(right_child);
	free(root);

	return 0;
}
