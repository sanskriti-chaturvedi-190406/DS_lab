#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* getNode(int value){
    struct Node* p= (struct Node*)malloc(sizeof(struct Node));
    p->data=value;
    p->next=NULL;
    return p;
};

void insertAtBeginning(struct Node** head, int value){
    struct Node* newNode= getNode(value);
    newNode->next=*head;
    *head=newNode;
}

int deleteAtBeginning(struct Node** head){
    if (*head==NULL){
        printf("Void deletion.");
        return 1;
    }
    else{
        int item= (*head)->data;
        struct Node* delNode= *head;
        *head= (*head)->next;
        free(delNode);
        return item;
    }
}

void traversal(struct Node** head){
    if(*head!=NULL){
        struct Node* temp=*head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}