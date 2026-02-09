#include<stdio.h>
#include<string.h>

#define maximum 50;
  char stack[50];
  int top= -1 ;//Just to initialize the first value to 0 for the future


void push(char a){
  stack[++top] = a ;
}

char pop(){
  return stack[top--];
 }




int main(){
  char string[100];
    printf("Enter the input expression: ");
    scanf("%s", string);
    int len = strlen(string);

    for (int i =0; i < len; i++) {
        if(string[i] == '{' || string[i] == '(' || string[i] == '[') {
            push(string[i]);
        } else if(string[i] == '}' || string[i] == ')' || string[i] == ']') {
            pop();
        }
    }

    if(top == -1) {
        printf("The expression is balanced!!");
    } else {
        printf("The expression is NOT balanced!!");
    }

    return 0;
}

