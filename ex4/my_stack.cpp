#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mutex>
#include "my_stack.hpp"
#include <unistd.h>
#include <iostream>
#include <cstring>



int location = sizeof(struct Node);
void* my_malloc (size_t size) 
{
    void* ptr = sbrk(location);
    location += sizeof(struct Node);
    return ptr;
}
bool isempty()
{
 if(top == NULL)
 return true; else
 return false;
}

int main()
{
return 0;
}
void _free (void* ptr) 
{
    sbrk(location);
    location -= sizeof(struct Node);
}



void push(struct stack *stack, char* data) 
{
    Node *ptr = new Node();
  ptr-> data = data;
  ptr->link = top;
  top = ptr;
}

void pop(struct stack stack) 
{
   if ( isempty() )
  cout<<"Stack is Empty";
 else
 {
  Node *ptr = top;
  top = top -> link;
  delete(ptr);
 }
}

char* Top(struct stack stack) {
      char* ans;
 if ( isempty() )
 {
         ans = "Stack is Empty";
 }

 else{
         ans = "Element at top is : ";
         ans = top->data;
 }
        return ans;
}

