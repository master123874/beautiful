#include<stdio.h>
int main()
{
	int i=1;
	double a=1,s=0,n=1;
	while(n<=100)
	{
		s+=a;
		i=-i;
		n++;
		a=i/n;
		
	}
	printf("%f",s);
	
	return 0;
	
} 
