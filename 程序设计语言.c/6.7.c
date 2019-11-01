#include<stdio.h>
int main()
{
	int i;
	double s,t,sum;
	t=sum=0;
	s=0.01;
	for(i=1;i<=30;i++)
	{
		t+=100000.0;
		sum+=s;
		s*=2;
	}
	printf("%f",sum);
	return 0;
} 
