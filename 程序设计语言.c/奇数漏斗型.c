#include<stdio.h>
int main()
{
	int n,i,j,k,a=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		
		   
		if(i<=n/2+1)
		{
			for(k=n-i-n/2;k>=1;k--)
			  printf(" ");
			for(j=1;j<=2*i-1;j++)
			  printf("*");
			printf("\n");  
		 
	    }
	    else
	    {
	    	for(k=1;k<i-n/2;k++)
	    	  printf(" ");
	    	for(j=1;j<=(i-2*a)*2-1;j++)
	    	  printf("*");
	    	printf("\n");  
	    	a++;  
		}
		  
	}
	
	return 0;
} 
