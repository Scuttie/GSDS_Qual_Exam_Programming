#include <stdio.h>

#define STUDENT_NUMS 5

struct studentType{
	char name[50];
	int ID;
	int midterm;
	int final;
	int total;
};

typedef struct studentType Student; //이제 studentType을 Student로 부를 수 있음.

void calculateTotal(Student *s); //Student pointer를 받아서 값을 계산하는 함수 선언

int main(void){
	Student s[STUDENT_NUMS]; //s라는 이름의 Student 구조체를 받는 array 생성
	
	for(int i = 0; i < STUDENT_NUMS; i++){
		printf("[Input for Student #%d]\n", i);
		printf("\tname: ");
		scanf("%s", s[i].name); //이름을 입력 받아 i번째 학생의 이름에 저장 
		//(어차피 string이라 array임. 그래서 & 필요 없음.)
		printf("\tID: ");
		scanf("%d", &s[i].ID); //ID를 입력 받아 i번째 학생의 ID address에 저장 (int)
		printf("\tmidterm: ");
		scanf("%d", &s[i].midterm);
		printf("\tfinal: ");
		scanf("%d", &s[i].final);
	}
	
	for(int i = 0; i < STUDENT_NUMS; i++){
		calculateTotal(&s[i]); //각 학생의 total score 계산 후 입력
	}
	
	for(int i = 0; i < STUDENT_NUMS; i++){
		printf("Total score for Student #%d(%s) is %d\n", i, s[i].name, s[i].total);
	}
	
	return 0;
}

void calculateTotal(Student *s){
	s->total = s->midterm + s->final;
}