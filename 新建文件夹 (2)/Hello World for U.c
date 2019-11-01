#include<stdio.h>
#include<string.h>
#define N 81
int getmax(char *a)
{
	int i,j;
	return (strlen(a)+2)/3;
}
int main()
{
	char a[N];
	gets(a);
	int i,j;
	int k=getmax(a);
	int n=strlen(a);
	int mid=n-k*2;
	for(i=0;i<k-1;i++)
	{
		printf("%c",a[i]);
		for(j=0;j<mid;j++)printf(" ");
		printf("%c\n",a[n-i-1]);
	}
	for(i=0;i<mid+2;i++)printf("%c",a[mid+i]);

}
