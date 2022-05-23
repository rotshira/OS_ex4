#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <string>
#include <assert.h>
#include <string.h>
#include "my_stack.cpp"
#include <stdbool.h>
using namespace std;

struct stack st;
int main_f()
 {
    char* test1 = "shira";
    char* test2 = "amit";
    push(&st, test1);
    push(&st, test2); 
    char* temp1 = Top(st); // temp1 = amit
    assert (strcmp(temp1, test2) == 0);
    pop(st);
    char* temp2 = Top(st); // temp2 = shira
    assert (strcmp(temp2, "shira")==0);
    pop(st);
     
     return 0;
 }





