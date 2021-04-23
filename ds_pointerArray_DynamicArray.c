#include <stdio.h>

int main() {
	/*
	포인터도 변수. 같은 자료형의 포인터를 많이 사용할 경우
	그것을 배열로 묶어서선언하는 것이 효율적
	*/
	char* string1, * string2, * string3, * string4;
	char* stringArray[4];

	stringArray[0] = "Gwangju";
	stringArray[1] = "Software";
	stringArray[2] = "Meister";
	stringArray[3] = "4th Student";

	for (int i = 0; i < sizeof(stringArray) / sizeof(stringArray[0]); i++) {
		printf("%s\n", stringArray[i]);
	}

	/*
	동적 할당
	위의 경우처럼 포인터 배열로서 문자열을 관리하는 것은
	'직접 대입'해서 초기화시키기 때문에 가능함.
	사용자에게 비정형화된 문자열(글자수 제한 X) 입력받는 경우?
	
	*/
	// case1. 공간 낭비가 생기는 예 (일부 문자열이 매우 긴 경우)
	char inputAry[3][10000];
	for (int i = 0; i < 3; i++) {
		printf("[%d]번째 문자열 입력 : ", i + 1);
		gets(inputAry[i]);
	}
	// case2. 해당 문제를 해결하기 위해 동적할당 - malloc - 을 사용
	char tempAry[10000];	// 임시로 입력값을 받기 위해 충분한 크기의 배열 선언
	char* str[3] = { 0 };	// 동적 할당한 후 그 주소를 연결할 포인터 배열
							// 모든 인덱스를 NULL로 초기화
	// 할당의 과정
	for (int i = 0; i < 3; i++) {
		printf("[%d]번째 문자열 입력 : ", i + 1);
		gets(tempAry);
		str[i] = (char*)malloc(strlen(tempAry) + 1);
		// 핵심! 문자열 저장 공간을 파악해서 그만큼만 할당한다. (NULL 포함될만큼)
		// 1. malloc('숫자'); void포인터를 반환 => "사이즈만큼의 공간을 메모리에 할당해줘~"
		// 2. (char *): 형변환 => "방금 내가 넘겨준 메모리 공간을 char *형태의 저장 공간으로 사용할거야"
	}

}