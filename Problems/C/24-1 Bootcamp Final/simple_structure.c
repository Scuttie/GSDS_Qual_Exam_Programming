#include <stdio.h>
#include <stdlib.h>

/* implement Student structure */
typedef struct{
    int student_id;
    int middle;
    int final;
    int total;
}Student;

/* implement set_total() */
void set_total(Student* student){
    student->total = student->middle + student->final;
}


/// Do not modify below (whole main function) ///
int main(int argc, char * argv[]){
    
    if((argc-1)%2!=0){
        printf("Invalid Input");
        return 0;
    }
    /* structure array initialization start */
    int num_mem = (argc-1)/2;

    Student members[num_mem];
    printf("There are %d students\n", num_mem);

    // Scores can be negative //
    for (int i=0;i<num_mem;i++){
        members[i].student_id=i+1;
        members[i].middle=atoi(argv[i*2+1]);
        members[i].final=atoi(argv[i*2+2]);
        members[i].total=0;
    }
    /* structure array initialization end */

    for (int j=0;j<num_mem;j++){
        set_total(members+j);
    }

    for(int k=0;k<num_mem;k++){
        printf("id: %d, total score : %d\n", members[k].student_id, members[k].total);
    }
}
///////////////////
