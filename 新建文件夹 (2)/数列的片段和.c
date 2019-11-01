#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	float a[n];
	int i;
	for(i=0;i<n;i++)scanf("%f",&a[i]);
	int j,k;
	float f=0;
	for(i=0;i<n;i++)
	  for(j=i;j<n;j++)
	    for(k=i;k<=j;k++)
	      f+=a[k];
	printf("%.2f",f);
}
