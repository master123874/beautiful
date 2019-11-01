#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int b;
	long int result=0;
	scanf("%d",&b); 
	result+=b;
	char ch;
	while((ch=getchar())!='\n')
	{
		scanf("%d",&b);
		if(ch=='+') result+=b;
		else printf("你输入的字符有错请输入'+'\n");
	}
	printf("%d",result);
} 
