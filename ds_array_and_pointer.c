#include <stdio.h>

void printAry(int ary[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", *(ary + i)); 
	}
}

void inputAry(int* ary, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d번째 배열 요소의 값 입력 : ", i+1);
		scanf_s("%d", (ary + i));
		//ary == 시작주소, ary[i] == i번째 배열 요소(값)
		//ary[i] == *(ary + i) // &ary[i] == (ary + i)

	}
}

int main() {
	////////////// example 01.
	int ary[5] = { 1,2,3,4,5 }; // 선언 - 5칸짜리 배열
	*ary = 10;	// ary[0] = 10;과 같은 역할 ,
				// ary가 배열의 시작 주소값을 가지고 있으므로 
	*(ary + 1) = 20;	// ary[1] = 20;과 같은 역할 
	
	for (int i = 0; i < 5; i++) {
		printf("%d ", ary[i]);
		printf("%d ", *(ary + i));
	}

	////////////// example 02.
	int funcAry[5] = { 1,2,3,4,5 };
	int size = sizeof(funcAry) / sizeof(funcAry[0]);

	printf("\n\n");
	printAry(funcAry, size);
	inputAry(funcAry, size);
	printAry(funcAry, size);
	
	
}