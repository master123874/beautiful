#include<stdio.h>
int main()
{
	int a,b,count=0;
	for(a=27;a<100;a++)
	  for(b=0;b<73;b++)
	   {
	   	if(b/10+b%10*10==a&&a-b==27)
	   	{
	   		count++;
	   		printf("%d  %d\n",a,b);
	    }
	   	
	   }
	    
	printf("%d",count);
	
	return 0;   
} 
