#include<stdio.h>
#define x 20
void Sum(int List[],int N);
int main()
{
	int a[x],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	Sum(a,n);
	
	return 0;
} 
void Sum(int List[],int N)
{
	printf("%d",List);
}
