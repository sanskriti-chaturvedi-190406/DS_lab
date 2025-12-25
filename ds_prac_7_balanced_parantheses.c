#include<stdio.h>
#include<string.h>
#define MAX 100
char s[MAX],top=-1;
void push(char c){
s[++top]=c;
}
char pop(){
    return s[top--];
}
int match(char a,char b){
    return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
}
int main(){
    char e[MAX];
    printf("Enter the expression:");
    scanf("%s",e);
    for(int i=0;i<strlen(e);i++){
        char c=e[i];
        if(c=='(' || c=='{' || c=='['){
            push(c);
        }
        else if(c==')' || c=='}' || c==']'){
            if(top==-1 || !match(pop(),c)){
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if(top==-1){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }
}