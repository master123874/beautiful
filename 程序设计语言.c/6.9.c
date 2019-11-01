#include<stdio.h>
int main()
{
	int a,d=1;
	long c,b=100000,s=0;
	c=30*100000;
	for(a=1;a<=30;a++)
	{
		s+=d;
		
		d=2*d; 
	}
	printf("%d",s);
	
	return 0;
} 
