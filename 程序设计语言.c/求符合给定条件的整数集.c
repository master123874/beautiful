#include<stdio.h>
int main()
{
	int n,i,j,k,count=0;
	int s=0,a[10][6];
	scanf("%d",&n);
	for(i=n;i<=n+3;i++)
	  for(j=n;j<=n+3;j++)
	    for(k=n;k<=n+3;k++)
	    {
	    	if(i!=j&&i!=k&&j!=k)
	    	{
	    		a[s][count]=i*100+j*10+k;
	    		count++;
			}
			if(count==6)
			{
				s++;
				count=0;
			}
			
		}
	for(i=0;i<=s-1;i++)
	{
		for(j=0;j<6;j++)
		{
			if(j<=4)
			printf("%d ",a[i][j]);
			else printf("%d",a[i][j]);
			
		}
		printf("\n");
	}
		    	
	  	
	return 0;	
}
