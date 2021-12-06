#include "rbtree.h"

#include <stdlib.h>
#include <stdio.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t *nilNode = (node_t *)calloc(1, sizeof(node_t));
  
  nilNode->color = RBTREE_BLACK;
  p->nil = nilNode;
  p->root = nilNode;
  
  return p;
}

// added by jongwoo
node_t * find_rotation_target(rbtree * tree, node_t * x) {
    node_t * curr = tree->root;

    while (curr != NULL) {
        // 회전하려는 값을 가진 노드를 찾은 경우
        if (curr->key == x->key) {
            // printf("%d 를 찾았습니다~!\n", curr->key);
            return curr;
        }

        // key 값을 비교하여 탐색
        if (curr->key < x->key)
            curr = curr->right;
        else 
            curr = curr->left;
    }
    return NULL;
}

void right_rotation(rbtree * tree, node_t * x){
    // TODO!
    node_t *target;
    node_t *y;

    target = find_rotation_target(tree, x);

    if (target == NULL) {
        return;
    }

    // 1. target의 left으로 y 설정
    y = target->left;
    // 2. y의 오른쪽 서브트리를 target의 왼쪽 서브트리로 옮김
    target->left = y->right;
    // 3. y의 오른쪽 노드가 NIL이 아니라면, y의 오른쪽 노드 부모를 target으로 설정
    if (y->right != NULL) {
        y->right->parent = target;
    }
    // 4. y의 부모 노드를 target의 부모 노드로 설정
    y->parent = target->parent;
    // 5. target의 부모 노드가 nil이라면, 트리 구조체의 root를 y로 설정
    if (target->parent == tree->nil)
        tree->root = y;
    // 6. target이 target 부모 노드의 왼쪽이면, target 부모의 왼쪽을 y로 설정
    else if (target == target->parent->left)
        target->parent->left = y;
    // 7. target이 target 부모 노드의 오른쪽이면, target 부모의 오른쪽을 y로 설정
    else
        target->parent->right = y;
    // 8. target을 y의 오른쪽으로 설정
    y->right = target;
    // 9. target의 부모를 y로 설정
    target->parent = y;
}

void left_rotation(rbtree * tree, node_t * x){
    // TODO!
    node_t *target;
    node_t *y;
    
    // 루트에서 삭제할 노드까지 이동
    target = find_rotation_target(tree, x);

    if (target == NULL) {
        return; 
    }

    y = target->right;
    target->right = y->left;
    
    if (y->left != tree->nil) 
        y->left->parent = target;
    
    y->parent = target->parent;
    
    if (target->parent == tree->nil) 
        tree->root = y;
    else if (target == target->parent->left)
        target->parent->left = y;
    else 
        target->parent->right = y;

    y->left = target;
    target->parent = y;
}
//

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

void rbtree_insert_fixup(rbtree *t, node_t *z) {
  node_t *y;
  
  while (z->parent->color == RBTREE_RED) {
    // z의 부모가 조부모의 왼쪽 서브 트리일 경우
    if (z->parent == z->parent->parent->left) {
      y = z->parent->parent->right;
      
      // CASE 1 : 노드 z의 삼촌 y가 적색인 경우
      if (y->color == RBTREE_RED) {
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      }
      // CASE 2 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
      else {
        if (z == z->parent->right) {
          z = z->parent;
          left_rotation(t, z);
        }
        // CASE 3 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        right_rotation(t, z->parent->parent);
      }
    }
    // z의 부모가 조부모의 왼쪽 서브 트리일 경우
    else {
      y = z->parent->parent->left;

      // CASE 4 : 노드 z의 삼촌 y가 적색인 경우
      if (y->color == RBTREE_RED) {
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      }
      // CASE 5 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
      else {
        if (z == z->parent->left) {
          z = z->parent;
          right_rotation(t, z);
        }
        // CASE 6 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        left_rotation(t, z->parent->parent);
      }
    }
    
    
  }
  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;
  node_t *z = (node_t *)calloc(1, sizeof(node_t));
  
  z->key = key;

  while (x != t->nil) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right; 
  }

  z->parent = y;
  
  if (y == t->nil) {
    t->root = z;
  }
  else if (z->key < y->key) {
    y->left = z;
  }
  else {
    y->right = z;
  }

  z->left = t->nil;
  z->right = t->nil;
  z->color = RBTREE_RED;

  rbtree_insert_fixup(t, z);

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}