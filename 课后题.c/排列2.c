#include<stdio.h>
#include<stdlib.h>
void output(int *p);
int main()
{
	int a[4];
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++,printf("\n"))
	{
		for(j=0;j<4;j++)
		   scanf("%d",&a[j]);
		output(a);
	}
	  
} 
void output(int *a)
{
	int i,j,k,m;
	int flag;
	for(i=0;i<4;i++,printf("\n"),flag=0)
	  for(j=0;j<4;j++)
	    for(k=0;k<4;k++)
	      for(m=0;m<4;m++)
	        if(a[i]!=a[j]&&a[i]!=a[k]&&a[i]!=a[m]&&a[j]!=a[k]&&a[j]!=a[m]&&a[k]!=a[m]) 
	        {
	        	if(flag==0)
	        	{
	        		printf("%d%d%d%d",a[i],a[j],a[k],a[m]);
	        		flag=1;
				}
				else printf(" %d%d%d%d",a[i],a[j],a[k],a[m]);
			}
}
