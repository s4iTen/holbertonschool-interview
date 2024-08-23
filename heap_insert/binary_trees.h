#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>

/* Structure for a binary tree node */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *heapify_up(heap_t *node);
void binary_tree_print(const binary_tree_t *);  /* Add this line */

#endif /* BINARY_TREES_H */
