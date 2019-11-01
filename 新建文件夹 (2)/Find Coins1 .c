#include<stdio.h>
int a[100000];
void sort(int *a,int n)
{
	int i,j,change=1;
	for(i=0;i<n&&change;i++)
	{
		change=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				change=1;
			}
		}
	}	
} 
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=0;i<m;i++)scanf("%d",&a[i]);
	sort(a,m);
    i=0,j=m-1;
    while(i<j)
	{
        if(i!=j&&a[i]+a[j]==n)
		{
            printf("%d %d",a[i],a[j]);
            return 0;
        }
        else if(a[i]+a[j]<n)i++;
        else j--;
    }
    printf("No Solution");
    return 0;
}
