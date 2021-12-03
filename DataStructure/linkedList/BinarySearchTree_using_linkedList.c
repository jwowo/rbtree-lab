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
    // 루트노드부터 탐색할 포인터 변수 선언
    Node *p = root;

    // 루트 노드부터 단말 노드까지 이진 탐색
    while (p != NULL)
    {
        // 탐색 성공시 해당 노드 반환
        if (p->key == x) {  
            print('찾았습니다~!');
            return p;
        }
        // 검색하고자 하는 값이 현재 노드의 값보다 크다면 현재 노드를 오른쪽 서브트리로 이동
        else if (p->key < x)    
            p = p->right;
        // 검색하고자 하는 값이 현재 노드의 값보다 작다면 현재 노드를 왼쪽 서브트리로 이동        
        else
            p = p->left;
    }

    // 탐색 완료 후까지 검색하고자 하는 값을 찾지 못했으면 NULL 반환 
    print("못찾았습니다~!");
    return NULL;
}