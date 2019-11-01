#include<stdio.h>
int m(int n,int (*p)[n],int *x,int *y);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    int i,j;
    int x,y;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",&a[i][j]); 
    if(m(n,a,&x,&y)) printf("%d %d",x,y);
    else printf("NONE");
	  
}
int m(int n,int (*p)[n],int *x,int *y)
{
	int i,j,k;
	int max,flag;
	for(i=0;i<n;i++)
	{
		max=0;
		flag=1;
		for(j=1;j<n;j++)
		{
			if(p[i][j]>p[i][max]) max=j;
		}
		for(k=0;k<n;k++)
		{
			if(p[i][k]==p[i][max]&&k!=max)
			{
				flag=0;
				break;
			}
		
		}
		if(flag==1)
		{
			for(k=0;k<n;k++)
			{
				if(p[k][max]<=p[i][max]&&i!=k)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==1)
		{
			*x=i;
			*y=max;
			return 1;	
		}		
	}
	return 0;
	
}
