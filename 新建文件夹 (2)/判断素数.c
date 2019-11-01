#include<stdio.h>
int judge(int n)
{
	int i;
	for(i=2;i<n;i++)
	  if(n%i==0)return 0;
	return 1;  
}
int main()
{
    long n;
    int i,flag=1;
    scanf("%ld",&n);
    int b[n],j;
    int t;
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
    	if(judge(b[i]))printf("Yes\n");
    	else printf("No\n");
    }
}
