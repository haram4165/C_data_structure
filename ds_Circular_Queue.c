// 목표 : N개의 공간에 N-1개의 데이터를 Enqueue, Dequeue할 수 있는 큐 구현
// 1. 한정된 배열 공간을 효율적으로 사용하기 위한 방법
//	- 나머지 연산자를 사용, 다음 인덱스가 범위를 초과할 경우 다시 0으로 돌아가게
// 2. N-1개를 사용하는 이유
// front == rear 큐가 비어있는 상태 or 꽉 차 있는 상태 구분이 안되는 문제 해결
// +@: 데이터의 갯수를 기반으로 비어있는 상태 & 꽉 찬 상태를 구분할 수도 있음
#include <stdio.h>

#define QUEUE_SIZE 10 // 인덱스 범위: 0~9

int queue[QUEUE_SIZE] = {0};
int front = 0, rear = 0; // 큐의 처음과 끝 위치를 가리키는 인덱스 (초기화)

// 이슈 1에 대한 해결
int NextPosition(int pos)
{
    // 1. 정석 코드
    return (pos + 1) % QUEUE_SIZE;
    // 2. 의미만 일치하는 코드
    //	if (pos == QUEUE_SIZE - 1)
    //		return 0;
    //	else
    //		return pos + 1;
}

void EnQueue(int data)
{
    if (NextPosition(rear) == front)
    { // 꽉 찼을 경우
        printf("큐에 데이터가 꽉참\n");
    }
    else
    { // 꽉 차지 않은 경우
        queue[rear] = data;
        rear = NextPosition(rear);
        // 함수를 사용하지 않은 경우
        //rear = (rear + 1) % QUEUE_SIZE;
    }
}

int DeQueue()
{
    if (front == rear)
    {
        printf("큐에 꺼낼 데이터가 없음\n");
        exit(-1);
    }
    else
    {
        int dequeueData = queue[front];
        front = NextPosition(front);
        return dequeueData;
    }
}

int main()
{
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    EnQueue(5);
    EnQueue(6);
    EnQueue(7);
    EnQueue(8);
    EnQueue(9);
    EnQueue(10);
    EnQueue(11);
    EnQueue(12);
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
}