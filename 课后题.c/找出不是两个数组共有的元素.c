#include<stdio.h>
int main()
{
    int m,n,i;
    int j,k=0;
    scanf("%d",&m);
    int a[m];
    for(i=0;i<m;i++)
      scanf("%d",&a[i]);
    scanf("%d",&n);
    int b[n];
    for(i=0;i<n;i++)
      scanf("%d",&b[i]);
    int c[20],count=0;  
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[j]!=a[i])
            {
                k++;
                if(k%n==0)
                {
                    c[count]=a[i];
                    count++;
                }
            }  
        }
        k=0;
    }
    k=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			if(a[i]!=b[j])
			{
				k++;
				if(k%m==0)
				{
					c[count]=b[j];
					count++;
				}
			}
		}
		k=0;
    }
    for(i=0;i<count-1;i++)
    {
    	for(j=i+1;j<count-1;j++)
    	{
    		if(c[j]==c[i])
    		{
    			for(k=j;k<count-1;k++)
    			  c[k]=c[k+1];
    			count--;
				j--;  
			}
		}
	}
    
	for(i=0;i<count-1;i++)
       printf("%d ",a[i]);
    printf("%d",a[count-1]);   
	return 0;
 
	
}
