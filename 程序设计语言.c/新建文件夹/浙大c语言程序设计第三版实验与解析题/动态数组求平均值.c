#include<stdio.h>
#include<stdlib.h>
#define N 100
int main()
{
	int *p=NULL,count=0,a[N],i=0;
	int j;
	double s=0;
	while(scanf("%d",&a[i])==1)
	{
		
		i++;
		count++;
		if(a[i]=='c') break;
	}
	p=(int *)malloc(sizeof(int)*count);
	


	for(j=0;j<i;j++)
	{
		p[j]=a[j];
		s+=p[j];
	}
	printf("%.2lf",s/count);
	
	for(j=0;j<count;j++)
	  free(p[j]);
	  
	return 0;  

}
