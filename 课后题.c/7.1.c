#include<stdio.h>
int main()
{
	int t,i;
	int a[10];
	for(i=0;i<10;i++)
	  scanf("%d",&a[i]);
	for(i=0;i<10/2;i++)
	{
		t=a[i];
		a[i]=a[10-i-1];
		a[10-i-1]=t;
    }
	for(i=0;i<10;i++)
	  printf("%d ",a[i]);   
}
