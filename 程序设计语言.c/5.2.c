#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=30;i++)
	  for(j=1;j<=30;j++)
	   if(4*i+2*j==90) printf("����%dֻ��������%dֻ\n",j,i);
	   
	return 0;   
} 
