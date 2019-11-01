#include<stdio.h>
int main()
{
	int year=1998;
	float r=0.011,people_1998=5e9,people_year=people_1998;
	do
	{
		people_year=people_year*(1+r);
		year++;
	}while(people_year<2*people_1998);
	printf("year=%d\n",year);
	return 0;
	
	
	
} 
