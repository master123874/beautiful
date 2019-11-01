#include<stdio.h>
int main()
{
	int a=1;
	double n=1.0,e;
	while(n>=10e-7)
	{
		e+=n;
		a*=1;
		n=1.0/a;
		a++;
		
	}
	
	printf("%f",e);
	
	return 0;
	
}
