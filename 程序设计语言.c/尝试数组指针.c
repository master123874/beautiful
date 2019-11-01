#include<stdio.h>
void c(int *p,int n)
{
	int *bend=p+n;
	for(;p<bend;p++)
	  printf("%4d",*p);
		
	printf("\n");

	
	
}
int main()
{
	int i,a[5]={1,2,3,4,5};
	c(&a,5);
	for(i=0;i<5;i++) printf("%4d",a[i]);
	
	return 0;
}
