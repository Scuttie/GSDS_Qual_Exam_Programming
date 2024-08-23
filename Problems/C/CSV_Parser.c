#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char filename[20];
    printf("Enter file name : ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    /* Write your code here */
    // hint1) You should use fgets(line, MAX_LINE_LENGTH, file) to read the line.
    // hint2) If it is first value of line, use strtok(line, ","). Otherwise, use strtok(NULL, ",")

    // 첫 번째 줄은 헤더이므로 읽어들인 후 무시
    fgets(line, MAX_LINE_LENGTH, file);

    // CSV 파일의 각 줄을 읽어들임
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // 쉼표 기준으로 자르는 데, 첫번째 읽기
        char *name = strtok(line, ",");
        // 쉼표 기준으로 자르는 데, 두번째 읽기
        char *grade = strtok(NULL, ",");

        // 형식에 맞게 출력
        if (name != NULL && grade != NULL) {
            printf("Name: %s, Grade: %s", name, grade);
        }
    }

    ////////////////////
    fclose(file);
    return 0;
}
