#include <stdio.h>

/*
    구조체를 사용하면 다양한 데이터들을 묶어서 하나의 자료처럼 다룰 수 있음
        1. 구조체의 형태를 컴파일러에 미리 알려주는 '구조체 선언'을 해야 함.
*/

// example1. 구조체 정의
struct student {
    int number;
    double grade;
};
// 세미콜론이 붙어야 함.
// int number ; 뒤에 ;를 붙이는 것처럼
// struct student     {int number; char name[20];}      ;

// example2. 구조체 활용
struct profile {
    char name[20];
    int age;
    double height;
    char* intro;
};

// example3. 구조체 반환
struct twoNumData {
    int num1;
    int num2;
};
struct twoNumData swap(struct twoNumData data) {
    int temp;
    temp = data.num1;
    data.num1 = data.num2;
    data.num2 = temp;
    return data;
};

int main() {
    // example 1. 구조체 선언
    struct student st1;     // struct student

    st1.number = 1;
    st1.grade = 4.3;

    printf("st1의 학번: %d, 학점: %.2f\n\n", st1.number, st1.grade);



    // example 2. 구조체 사용1
    struct profile gsm;

    strcpy(gsm.name, "박하람");
    gsm.age = 18;
    gsm.height = 67.8;

    gsm.intro = (char*)malloc(80);     // 80byte 할당
    printf("자기소개 :");
    fgets(gsm.intro, 80, stdin);        // 개행문자도 저장함

    printf("이름: %s\n", gsm.name);
    printf("나이: %d\n", gsm.age);
    printf("몸무게: %.2f\n", gsm.height);
    printf("자기소개: %s\n", gsm.intro);
    free(gsm.intro);
    printf("\n\n");



    // example 3. 구조체를 사용한 데이터 swap (실제로는 구조체 한 개를 반환받는 것이지만, 덩어리채 넘어오므로)
    struct twoNumData number;
    number.num1 = 10;
    number.num2 = 20;
    number = swap(number);
    printf("num1: %d, num2: %d\n\n", number.num1, number.num2);

    return 0;
}