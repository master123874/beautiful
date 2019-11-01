#include<stdio.h>
int main()
{
	int a=0,j=1;
	double n=1.0,e=0;
	while(n>=10e-7)
	{
		a++;
		e+=n;
		j=j*a;
		n=1.0/j;
		
		
	}
	
	printf("%f",e);
	
	return 0;
	
}
