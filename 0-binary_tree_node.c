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
	// Example usage of the binary_tree_node function
	binary_tree_t *root = binary_tree_node(NULL, 1);
	binary_tree_t *left_child = binary_tree_node(root, 2);
	binary_tree_t *right_child = binary_tree_node(root, 3);

	root->left = left_child;
	root->right = right_child;

	printf("Binary Tree Structure:\n");
	print_binary_tree(root, 0);

	// Don't forget to free allocated memory
	// In a real application, you should free the tree using a proper deallocation function.
	free(left_child);
	free(right_child);
	free(root);

	return 0;
}
