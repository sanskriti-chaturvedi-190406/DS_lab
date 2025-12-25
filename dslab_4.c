//How to convert C++ code for SLL to C
/*
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* getNode(int value){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
}
*/

//Complexity of
//Insertion:
//    1. At beginning- O(1)
//    2. At End- O(n)
//    3. After- Search time + O(1)
//Deletion:
//    1. At beginning- O(1)
//    2. At End- O(n)
//    3. After- Search time + O(1)

//linked list implementation of stack
/*
void push(Top, data)
Begin:
    insertAtBeginning(Top, data)
End

int pop(Top)
Begin:
    if(Top==NULL)
        write "Stack Empty"
        return -1
    else
        popped_element= deleteAtBeginning(Top)
        return X
End

int Peek(Top)
Begin:
    if Top==NULL
        write "Stack Empty"
        return -1
    else
        return Top.data
End
*/

#include <stdio.h>
#include "dslab_4.h"//custom header file

struct Node* Top= NULL;

void push(int value){
    insertAtBeginning(&head,value);
}

void pop(struct Node** head){
    if(*head)
        deleteAtBeginning(head);
    else    
        printf("Stack underflow!\n");
}

void peek(){
    
}

int main(){
    /*
    insertAtBeginning(&head,1);
    insertAtBeginning(&head,2);
    insertAtBeginning(&head,3);
    insertAtBeginning(&head,4);
    insertAtBeginning(&head,5);
    traversal(&head);
    int x;
    x=deleteAtBeginning(&head);
    printf("%d deleted succesfully!\n");
    traversal(&head);
    return 0; 
    */
}