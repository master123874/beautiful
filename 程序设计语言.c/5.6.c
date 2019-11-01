#include<stdio.h>
int main()
{
	
	double t=1,s,n=1,j=1;
	while(t>=10e-7)
	{
		s+=t;
		n=n*j;
		t=1.0/n;
		j++;
		
	}
	
	printf("%f",s);
	
	return 0;
} 
