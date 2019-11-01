#include<stdio.h>
int main()
{
	int i,j,count=0;
	for(i=1;i<=9;i++)
	   for(j=1;j<=9;j++)
	    {
	    	printf("%d*%d=%-4d",i,j,i*j);
	    	count++;
	    	if(count%9==0)printf("\n");
	    	
		}
		
	     
	
	
	return 0;	 
	
	   	
	   
	
	
	
} 
