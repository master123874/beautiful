#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[30]={1,2,3,4,5,6,7,8,9,10},count=10;
	int high=count-1,low=0,mid=(high+low)/2;
	int *p,i=0,k,j;
	p=(int *)malloc(20*sizeof(int));
	if(p==NULL) exit(0);
	while(scanf("%d",&p[i])==1)
	{
		if(p[i]>a[mid])
		
		{
			low=mid+1;
			for(j=low;j<=high;j++)
			{
				if(a[j]<=p[i]&&p[i]<=a[j+1])
				{
					for(k=j+2;k<=high;k++)
					{
						a[k+1]=a[k];
					}
					a[j+1]=p[i];
					count++;
				}
				else
				{
					a[count]=p[i];
					count++;
				}
				
			}
			i++;
		}
		else
		{
			high=mid-1;
			for(j=0;j<=mid-1;j++)
			{
				if(a[j]<=p[i]&&p[i]<=a[j+1])
				{
					for(k=j+2;k<=count;k++)
					{
						a[k+1]=a[k];
					}
					a[j+1]=p[i];
					count++;
					
					
				}
				else
				{
					a[mid-1]=p[i];
					for(k=mid-1;k<count;k++)
					{
						a[k+1]=a[k];
					}
					count++;
					
				}
				
			}
		}
		
	} 
	for(j=0;j<count;j++)
	{
		printf("%d ",a[j]);
	}
	
	return 0;
} 
