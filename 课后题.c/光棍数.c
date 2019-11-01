#include<stdio.h>
#include<string.h>
#define N 10000
int main()
{
    int single[N];
    int i=0;
    int count=0;
    single[count++]=1;
    int x;
    scanf("%d",&x);
    int s[N];
    int flag=1;
    int t=0;
    int p=0;
    while(1)
    {
    	for(;i<count;i++)
    	{
    		p=p*10+single[i];
    		s[t]=p/x;
    		t++;
    		p-=(p/x)*x;
		}
		if(!p)
		{
			for(i=0;i<t;i++)
			{
				if(s[i])printf("%d",s[i]);
			}
			printf(" %d",count);
			return 0;
		}
		else
		{
			single[count]=1;
			count++;
		}
	}
	
}
