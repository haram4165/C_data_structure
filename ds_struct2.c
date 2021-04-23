#include <stdio.h>

/*
1. 구조체의 포인터 연결 *
2. 구조체 배열
3. typedef **
4. 자기참조구조체 **
*/

// example1.
struct exam {
	int kor;
	int math;
	int eng;
};

// example3. typedef 재정의
//unsigned int abc; -> typedef unsigned int Uint;
	// case 1. 기존에 정의된 구조체를 재정의
typedef struct exam Exam;
	// case 2. 구조체를 정의함과 동시에 typedef 적용
typedef struct {
	char name[20];
	int hakbun;
} Student;

// exapmle 4.자기참조구조체
typedef struct list {
	int data;
	struct list* next;
} Node;

int main() {
	struct exam phr;
	phr.kor = 100;
	phr.math = 50;
	phr.eng = 75;
	struct exam* examPointer = &phr;
	examPointer->kor /= 2;	// phr.kor /= 2;
	examPointer->math /= 2;
	examPointer->eng /= 2;
}	