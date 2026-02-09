#include <stdio.h>
#include<ctype.h>             
#define max 50                
char s[max];
int top = -1;
void push(char element)     
{
	s[++top]=element;
}
char pop(){
	return(s[top--]);
}
int priority(char element){
	switch (element)
	{
	case '#':
	return 0;
	case '(':
	return 1;
	case '+':
	case '-':
	return 2;
	case '*':
	case '/':
	return 3;
	default: return -1;
	}
}
 
int main(void) {
	char infix[50],postfix[50],ch,element;
	int i=0,k=0;
	printf("Enter infix expresion:\n");
	scanf("%s",infix);
	push('#');                                
	while((ch = infix[i++])!='\0'){
		if(ch=='(')
		push(ch);
		else if(isalnum(ch))
		postfix[k++]=ch;
		else if(ch==')'){
			while(s[top]!='(')
			{
			postfix[k++]=pop();
			}
			element=pop();                    
		}
		else{
			while(priority(s[top])>=priority(ch))   
			postfix[k++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#'){
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	printf("\n\nGiven Infix Mathematical Expression is : %s and the  Postfix Expression is : %s\n", infix, postfix);
	return 0;
}