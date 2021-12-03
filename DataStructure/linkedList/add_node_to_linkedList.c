#include <stdio.h>
#include <stdlib.h> // malloc, free 함수가 선언된 헤더 파일

struct NODE {   // 연결 리스트의 노드 구조체
    struct NODE *next;  // 다음 노드의 주소를 저장할 포인터
    int data;           // 데이터를 저장할 멤버
};

// target 노드 뒤에 데이터를 추가하는 함수
void addFirst(struct NODE *target, int data)
{
    struct NODE *newNode = malloc(sizeof(struct NODE)); // 새 노드 생성
    newNode->next = target->next;   // 새 노드의 다음 노드에 기준 노드의 다음 노드 지정
    newNode->data = data;           // 데이터 저장
    target->next = newNode;         // 기준 노드의 다음 노드에 새 노드 지정
}

int main(void)
{
    struct NODE *head = malloc(sizeof(struct NODE));    // head 노드 생성
    head->next = NULL;

    addFirst(head, 10); // head 노드 뒤에 data가 10인 새 노드 추가
    addFirst(head, 20); // head 노드 뒤에 data가 20인 새 노드 추가
    addFirst(head, 30); // head 노드 뒤에 data가 30인 새 노드 추가

    struct NODE *curr = head->next; // 연결 리스트 순회용 포린터에 첫 번째 노드의 주소 저장

    while (curr != NULL)
    {
        struct NODE *next = curr->next; // 현재 노드의 다음 노드 주소를 임시로 저장
        free(curr);     // 현재 노드의 메모리 해제
        curr = next;    // 포인터에 다음 노드의 주소 저장
    }

    free(head); // head 노드 메모리 해제

    return 0;
}