#include<stdio.h>
void main()
{
	int a,b,max;
	printf("\n请输入两个整数(a,b):");
	scanf("%d%d",&a,&b);
	max=a;
	if (b>max)
	    max=b;
	printf("max=%d",max);    
	
}
