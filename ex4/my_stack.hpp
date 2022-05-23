#include <stdbool.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
using namespace std;

#include <stdio.h>


struct Node
{
char *data;
struct Node *link;
};

struct Node* top = NULL;

struct stack 
{
    struct Node *head;
    bool isEmpty;
    int size_s;
};

void push(struct stack*, char* s) ;
char* Top(struct stack st);
void pop (struct stack st);
bool isempty();