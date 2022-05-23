#include <iostream>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
using namespace std;
//code for stack took from https://www.codewhoop.com/stack/stack-using-linked-list.html
//Structure of the Node
pthread_mutex_t lock_new = PTHREAD_MUTEX_INITIALIZER;

char buffer[1024];
struct Node
{
string data;
Node *link;
};

// top pointer to keep track of the top of the stack
Node *top = NULL;

//Function to check if stack is empty or not
bool isempty()
{
 if(top == NULL)
 return true; else
 return false;
}

//Function to insert an element in stack
void push (string value)
{
  Node *ptr = new Node();
  ptr->data = value;
  ptr->link = top;
  top = ptr;
}

//Function to delete an element from the stack
void pop ( )
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

// Function to show the element at the top of the stack
string showTop()
{
        string ans = "";
 if ( isempty() ){
         ans = "Stack is Empty";
 }
//   cout<<"Stack is Empty";
 else{
         ans = "Element at top is : ";
         ans += top->data;
 }
//   cout<<"Element at top is : "<< top->data;
        return ans;
}

// Function to Display the stack
void displayStack()
{
 if ( isempty() )
  cout<<"Stack is Empty";
 else
 {
  Node *temp=top;
  while(temp!=NULL)
  {   cout<<temp->data<<" ";
   temp=temp->link;
  }
  cout<<"\n";
 }
 }

// Main function
void* mainfunc(void *arg)
{
if (pthread_mutex_init(&lock_new, NULL) != 0) { //init lock
        printf("\n mutex init has failed\n");
        // return 1;
}
 int newSocket = *((int *)arg);
 
 int choice, flag=1;
 string value,action;
 char cstr[1025];
 //Menu Driven Program using Switch

 while( flag == 1)
 {
 
 
 int numbytes;
 memset(buffer, '\0', sizeof(buffer));
 if ((numbytes = recv(newSocket, buffer, 1024, 0)) == -1) {
        perror("recv");
        exit(1);
}
action = buffer;
 pthread_mutex_lock(&lock_new);
 if(action == "PUSH"){
     choice = 1;
 }
 if(action == "POP"){
     choice = 2;
 }
 if(action == "TOP"){
        choice = 3;
 }
 if(action == "display"){
     choice = 4;
 }
  if(action == "exit"){
     choice = 5;
 }
pthread_mutex_unlock(&lock_new);
 switch (choice)
 {
 case 1: 
        if ((numbytes = recv(newSocket, buffer, 1024, 0)) == -1) {
                perror("recv");
                exit(1);
        }
         push(buffer);
         break;
 case 2: pop();
         break;
 case 3:
        memset(cstr, '\0', sizeof(cstr));
        strcpy(cstr,showTop().c_str());
        if(send(newSocket,cstr,1024,0)==-1){
                perror("can't send...");
        }
        
         break;
 case 4: displayStack();
         break;
 case 5: flag = 1;
         break;
         
 }


 }

// close(newSocket);
// pthread_exit(NULL);
return NULL;
}


