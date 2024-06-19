#include<stdio.h>
#include<malloc.h>
int top=0,st[20];
char inf[40],post[40];
void postfix();
void push(int);
char pop();	
void main()
{
printf("Enter the infix expression:");
scanf("%s",inf);
postfix();
}
void postfix()
{int i,j=0;
for(i=0;inf[i]!=0;i++)
{switch(inf[i])
{
case '+':while(st[top]>=1)
post[j++]=pop();
push(1);
break;
case '-':while(st[top]>=1)
post[j++]=pop();
push(2);
break;
case '*':while(st[top]>=3)
post[j++]=pop();
push(3);
break;
case '/':while(st[top]>=4)
post[j++]=pop();
push(4);
break;
case '^':
post[j++]=pop();
push(5);
break;
case '(':push(0);
break;
case ')':while(st[top]!=0)
post[j++]=pop();
top--;
break;
default:
post[j++]=inf[i];
}}
while(top>0)
post[j++]=pop();
printf("\nPostfix expression is =>\n\t\t%s",post);
}void push(int ele)
{
top++;
st[top]=ele;
}char pop()
{int el;
char e;
el=st[top];
top--;
switch(el)
{case 1:
e='+';
break;
case 2:
e='-';
break;
case 3:
e='*';
break;
case 4:
e='/';
break;
case 5:
e='^';
break;
}return(e);
}
