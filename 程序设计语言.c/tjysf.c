#include<stdio.h>
#include<conio.h>
void main()
{
	char ch;
	ch=getchar();
	ch=ch>='a'&&ch<='z'?ch-32:ch;
	putchar(ch);
	
 } 
