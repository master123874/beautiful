#include<stdio.h>
int main()
{
    int m,n;
    int i=2,count=0,z=0;
    int flag=1,j;
    scanf("%d%d",&m,&n);
    while(count<n)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag) 
        {
        	count++;
        	if(count>=m)
            {
            	if(count==n)
            	{
            		printf("%d",i);
            		return 0;
				}
            	z++;
            	if(z%10<=9&&z%10>0)printf("%d ",i);
            	if(z%10==0)printf("%d\n",i);
                
            	
            }
		}
        i++; 
        flag=1; 
    }
    
}
