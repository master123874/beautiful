#include<stdio.h>
int judge(int t,int *a,int n,int t1)
{
	int i;
    for(i=0;i<n;i++)
    {
    	if(i==t1)continue;
    	else if(a[i]==t)return 0;
	}
    return 1;  
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int a[n];
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
    	if(judge(a[i],a,n,i))
    	{
    		printf("%d",a[i]);
    		return 0;
		}
	}
	printf("None");
}
