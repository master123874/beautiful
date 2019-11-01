#include<stdio.h>
#include<math.h>
#define Pi 3.1415926535
#define N 91
#define M 46
int main()
{
	
	int i,count=0;
	double a[N],b[M];
	for(i=0;i<N;i++)
	{
		a[i]=sin((float)i/180*Pi);
		printf("%.5lf ",a[i]);
		count++;
		if(count%6==0) printf("\n");
	}
	printf("\n");
	count=0;
	for(i=0;i<M;i++)
	{
		b[i]=tan((float)i/180*Pi);
		printf("%.2lf ",b[i]);
		count++;
		if(count%6==0) printf("\n");
	}
	printf("\n");
	
	return 0;
} 
