#include<stdio.h>
int retu(int m[],int n,int t)
{
	int count=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(t<=m[i])count++;
	}
	return count;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k,t,t1=1;
    int m[n];
    for(i=0;i<n;i++)
        scanf("%d",&m[i]);
    int count;
    for(i=0;i<n;i++)
    {
    	printf("#%d\n",i+1);
    	t1=i+1;
    	for(j=0;j<m[i];j++)
    	{
    		count=retu(m,n,j+1);
    		if(count==1)count=2;
    		printf("%d",t1);
    		t1+=count;
    		for(k=1;k<10;k++)
    		{
    			printf(" %d",t1);
    			t1+=count;
			}
			printf("\n");
		}
	} 
}
