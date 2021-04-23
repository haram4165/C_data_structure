#include <stdio.h>

int main() {
    /*
    C에서 문자열을 처리하는 방식
        1. 배열을 기반으로 한 char들의 집합
        2. 시작 주소를 가지고 있고, NULL (\0) 문자가 문자열의 끝을 알림
        3. (마지막 NULL 문자가 들어갈 만큼)충분한 크기의 배열이 존재해야 함.
        4. NULL문자는 콘솔창에서 공백과 같이 처리되어 표시(글자가 눈에 보이지는 않음)
    */
    char str1[] = "Gwangju Software Meister GO!";
    char str2[30] = "2021 자료구조 2학년 3반 앞번호";
    // 한글은 2byte 차지. %c를 두개 붙여주면 한 글자 출력. %c %c 같이 띄어쓰기를 사용할 경우 글자가 깨짐

    for (int i = 0; i < sizeof(str1) / sizeof(str1[0]); i++)
        printf("%c", str1[i]);
    printf("\n");
    for (int i = 0; i < sizeof(str2) / sizeof(str2[0]); i++)
        printf("%c", str2[i]);
    printf("\n");



    /*
    배열은 주소의 시작값(특정한 위치의 주소값을 가지고 있는 변수)이지만 일반 대입문은 오류가 발생함
    배열명은 특정한 주소를 가리키고 있는 상수형 포인터임. 배열 자체가 주소를 담는 역할을 수행하지 않음.
    */
    // str2 = "2021 여름방학 C 프로그래밍";     - 오류 발생



    /*
    strcpy 함수를 통해 이전 배열 저장 공간을 벗어나지 않는 길이의 문자열을 대입하거나 복사할 수 있음.
    */
    strcpy(str1, "GSM High School");        // str[] 형태로 초기화하여 배열 크기를 시각적으로 가늠하기 어려움...
    strcpy(str2, str1);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);



    /*
    포인터를 활용하면 특정한 문자값을 배열에 대입하지 않고 직접 출력할 수 있음.
    %s는 메모리상의 어딘가 새로운 위치를 가리키게 되고, 널문자(\0)가 나올때까지 한 글자씩 반복하여 출력
    */
    char* pStr = "2020 자료구조";
    printf("%s\n", pStr);
    pStr = "2021 자료구조";
    printf("%s\n", pStr);



    /*
    문자열 입력하기 - 무조건 크기가 충분한 '배열'을 사용해야 함.
        1. scanf("%s", str); -> 버퍼를 사용. 공백문자 단위로 버퍼가 작동. 띄어쓰기를 담지 못함.
        2. gets(str); -> 공백이나 탭 등을 포함하여 문자열 한 줄을 입력받음. Enter에 반응하여 \n대신 \0을 붙임
        3. fgets(str, sizeof(str), stdin); -> 배열의 최대 크기 - sizeof(str) - 만큼만 문자열 입력. 개행문자까지 배열에 저장한 후 \0을 붙임
    */
    char inputStr[100];
    printf("문자열 입력: ");
    scanf_s("%s", inputStr);      //, fgets(inputStr), fgets(inputStr, sizeof(inputStr), stdin)
    printf("%s\n", inputStr);



    /*
    표준 입력 함수의 버퍼 공유 문제
    버퍼를 사용하는 함수는 개행문자까지 버퍼에 저장(gets()는 해당 없음)해놓으므로,
    여러 개의 입력을 받을 때 다음 입력을 \n으로 사용해버리는 문제가 발생
    개행문자를 소진해줌으로써 문제를 해결 할 수 있음.
    참고자료 - https://modoocode.com/32
    */
    int age;
    char name[20];

    printf("나이 입력: ");
    scanf_s("%d", &age);
    // getchar();//   -   fgetc(stdin)으로 대체 가능,   버퍼에서 하나의 문자를 읽어서 반환, 반환문자는 버림
    printf("이름 입력: ");
    gets(name);
    // scanf("%s", name);   -   스트링의 경우 공백 문자들은 무시하고 실질적 문자열(공백문자가 아닌 것들)가 입력이 되면 읽어들이기 시작
    // scanf(%c", ch);   -   한 글자를 읽어들이므로 버퍼 공유 문제가 발생함.
    printf("나이: %d, 이름: %s\n", age, name);



    /*
    문자열 관련 함수들
        1. strcpy - 복사
        2. strcat - 이어붙이기 ~ 특히 배열의 크기가 매우 커야 함! 널 문자의 위치를 찾으므로 반드시 초기화가 되어있어야 함
        3. strcmp - 비교하기
        4. strlen - String의 길이 구하기
    */
    char exampleStr1[100] = "str1";
    char exampleStr2[100] = "str2";

    strcat(exampleStr1, exampleStr2);     // str1에 str2를 이어붙임
    printf("exStr1: %s, length: %d\n", exampleStr1, strlen(exampleStr1));

    strcpy(exampleStr1, exampleStr2);
    printf("exStr1: %s,\t exStr2: %s\n", exampleStr1, exampleStr2);

    printf("strcmp함수: 문자열이 같으면 0, 다르면 0 이외의 숫자: %d\n", strcmp(exampleStr1, exampleStr2));


    return 0;
}