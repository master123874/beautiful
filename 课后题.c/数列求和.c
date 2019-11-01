#include<stdio.h>
int main()
{
	int a,b;
	double s=0;
	int i=1;
	scanf("%d%d",&a,&b);
	int t=a;
	while(i<=b)
	{
		s+=a;
		a=a*10+t;
		i++;
	}
	printf("%.lf",s);
	
}
