 #include<stdio.h>
#include<string.h>
int isprime(int n)
{
    int i;
    if(n<=1)return 0;
    for(i=2;i*i<=n;i++)
      if(n%i==0)return 0;
    return 1;  
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    char a[m+1];
    scanf("%s",a);
    int i,j;
    int count=0,t=0;
    for(i=0;i<strlen(a);i++)
    {
    	count++;
    	t=t*10+a[i]-48;
    	if(count==n)
    	{
    		if(isprime(t))
    		{
    			for(j=i-count+1;j<=i;j++)
    				printf("%c",a[j]);
    			return 0;	
			}
			else
			{
				i=i-count+1;
				t=0;
				count=0;
			}
		}
    }	
	printf("%d",404);
}
