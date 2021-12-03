/*
이진 탐색 트리란 원소를 특정한 조건에 따라 정렬해놓은 이진 트리
모든 원소는 유일한 키 값을 갖는다
왼쪽 서브트리의 모든 원소들은 루트의 키보다 작은 값을 갖는다
오른쪽 서브트리의 모든 원소들은 루트의 키보다 큰 값을 갖는다
왼쪽 서브트리와 오른쪽 서브트리도 이진탐색트리이다(재귀적)
이 투리안에 어떤 노드를 루트로 잡아도 항상 위 조건이 참이어야 한다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char key;
    struct _Node *left;
    struct _Node *right;
} Node;

Node* searchNode(Node *root, char x);
Node* insertNode(Node *root, char x);
Node* deleteNode(Node *root, char x);

int main(void)
{
    return 0;
}

Node* searchNode(Node *root, char x)
{
    Node *p = root;

    while (p != NULL)
    {
        if (p->key == x) {
            print('찾았습니다~!');
            return p;
        }
        else if (p->key < x)
            p = p->right;
        else
            p = p->left;
    }

    print("못찾았습니다~!");
    return NULL;
}