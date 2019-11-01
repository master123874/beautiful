#include<stdio.h>
#include<math.h>
int main()
{
	int a[6][6];
	int i,j=0;
	for(i=0;i<6;i++)
	  for(j=0;j<6;j++)
	    scanf("%d",&a[i][j]);
	int max[6];
	for(i=0;i<6;i++)
	
	{
		max[i]=abs(a[j][i]);
		for(;j<6;j++)
		{
			if(abs(a[j][i])>=max[i])
			{
				max[i]=abs(a[j][i]);		
			}	 
		}	
    }
    for(i=0;i<6;i++)
    {
    	for(j=0;j<6;j++)
    	{
    		if(abs(a[j][i])==max[i])
    		{
    			a[j][j]=a[j][i];
    			break;
			}
		}
	}
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		  printf("%d ",a[i][j]);
		printf("\n");  
	}
	    
	    
	    
		
	return 0;	  
    
} 
