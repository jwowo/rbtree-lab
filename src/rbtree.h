#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h>

typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct node_t {
  color_t color;
  key_t key;
  struct node_t *parent, *left, *right;
} node_t;

typedef struct {
  node_t *root;
  node_t *nil;  // for sentinel
} rbtree;

rbtree *new_rbtree(void);
void delete_rbtree(rbtree *);

node_t *rbtree_insert(rbtree *, const key_t);
node_t *rbtree_find(const rbtree *, const key_t);
node_t *rbtree_min(const rbtree *);
node_t *rbtree_max(const rbtree *);
int rbtree_erase(rbtree *, node_t *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);

// --- added by jongwoo ---
// --- functions related to rotation ---
node_t * find_rotation_target(rbtree * tree, node_t * x);
void right_rotation(rbtree * tree, node_t * x);
void left_rotation(rbtree * tree, node_t * x);

// --- functions related to insert ---
void rbtree_insert_fixup(rbtree *tree, node_t *z);
//

#endif  // _RBTREE_H_
