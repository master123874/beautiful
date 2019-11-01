#include<stdio.h>
float average(int x,int y,int z)
{
	float av;
	av=(x+y+z)/3.0;
	return av;
	
 } 
 main()
 {
 	int a,b,c;
 	float aver;
 	printf("Please input the a,b,c:");
 	scanf("%d%d%d",&a,&b,&c);
 	aver=average(a,b,c);
 	printf("the average is %f.\n",aver);
 }
