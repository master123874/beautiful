#include<stdio.h>
int main()
{
	int a,i,j,k,b=1;
	printf("请输入一个奇数：");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		
		if(i<=a/2)
		{
			for(j=i;j<=a/2;j++)
		      printf(" ");
		    for(k=1;k<=2*i-1;k++)
			  printf("A");
			printf("\n");   
		}
		if(i==a/2+1)
		{
			for(j=1;j<=a/2;j++)
			 printf("A");
			printf(" ");
			for(j=1;j<=a/2;j++)
			  printf("A");
			printf("\n");   
		}
		if(i>a/2+1)
		{
			for(j=i;j>a/2+1;j--)
			 printf(" ");
			for(j=1;j<=(i-2*b)*2-1;j++)
			  printf("A");
			b++;  
			printf("\n");  
		}
	 	   
	} 
	
	return 0;
} 
