#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char stack[30];
int top=-1;
int getnum(char data[],int loc)
{
    if((data[loc]=='-'||data[loc]=='+')&&loc-1>=0&&(isdigit(data[loc-1])||data[loc-1]==')'))
        return 0;
    int count=0;
    if(data[loc]=='-'||data[loc]=='+'){
        count++;
        loc++;
    }
    while(data[loc]&&strchr("+-*/()",data[loc])==NULL){
        count++;
        loc++;
    }
    return count;
}
void deal(char ch)
{
    if(ch=='+'){
        while(top>=0&&stack[top]!='(')
            printf(" %c",stack[top--]);
        stack[++top]='+';
    }
    else if(ch=='-'){
        while(top>=0&&stack[top]!='(')
            printf(" %c",stack[top--]);
        stack[++top]='-';
    }
    else if(ch=='*'){
        while(top>=0&&stack[top]!='('&&stack[top]!='+'&&stack[top]!='-')
            printf(" %c",stack[top--]);
        stack[++top]='*';
    }
    else if(ch=='/'){
        while(top>=0&&stack[top]!='('&&stack[top]!='+'&&stack[top]!='-')
            printf(" %c",stack[top--]);
        stack[++top]='/';
	}
}
int main()
{
    int i,j;
    int flag=0;
    char data[30];
    gets(data);
    for(i=0;data[i];i++){
        int num;
        if((num=getnum(data,i))!=0){
            char temp[30];
            for(j=0;j<num;j++)
                temp[j]=data[i+j];
            temp[j]='\n';   /*模拟输入结束标志*/ 
            i=i+num-1;
            double result=atof(temp);
            if(flag)
              printf(" %g",result);
            else
              printf("%g",result);
            flag=1;
        }
        else if(data[i]=='(')
            stack[++top]='(';
        else if(data[i]==')'){
            while(stack[top]!='('){
                printf(" %c",stack[top--]);
            }
            top--;
        }
        else if(strchr("+-*/",data[i])!=NULL){
            deal(data[i]);
        }
    }
    for(i=top;i>=0;i--)
        printf(" %c",stack[i]);
    return 0;
}
