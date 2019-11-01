#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    int a[n],i;
    for(i=0;i<n;i++)a[i]=i+1;
    int t=n;
    while(t>=1)
    {
        if(t==1)
        {
            for(i=0;i<n;i++)
            {
                if(a[i])
                	printf("%d",a[i]);
            }
            return 0;
        }
        else
        {
	        for(i=0;i<n;i++)
	        {
	            if(a[i]!=0)
	            {
	                cnt++;
	                if(cnt==3)
	                {
	                    a[i]=0;
	                    cnt=0;
	                    t--;
	                }
	            }
	        }
		}

    }
}
