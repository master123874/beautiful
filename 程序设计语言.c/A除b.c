#include<stdio.h>
int main()
{
	long unsigned a,c;
	int b,d;
	scanf("%lu%d",&a,&b);
	c=a/b;
	d=a%b;
	printf("%lu %d",c,d);
	
	return 0;
	
} 
