#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define N 1001
int main()
{
    char ch;
    scanf("%c",&ch);
    getchar();
    int i,j;
    char a[N];
    if(ch=='C')
    {
        gets(a);
        int count;
        for(i=0;i<strlen(a);i++)
        {
            count=1;
            for(j=i+1;j<strlen(a);j++)
            {
                if(a[j]==a[i])count++;
                else break;
            }
            if(count!=1)
            {
                printf("%d%c",count,a[i]);
                i+=count-1;
            }
            else printf("%c",a[i]);
        }
    }
    else if(ch=='D')
    {
    	gets(a);
    	int count;
    	for(i=0;i<strlen(a);i++)
    	{
    		if(isdigit(a[i]))
    		{
    			count=1;
    			for(j=i+1;j<strlen(a);j++)
    			{
    				if(isdigit(a[j]))
    				{
    					count++;
					}
					else break;
				}
				int t=0,t2=0;
				for(j=i;j<count+i;j++)
				{
					t+=(a[j]-'0')*pow(10,count-t2-1);
					t2++;
				}
				for(j=0;j<t;j++)printf("%c",a[i+count]);
				i+=count;
			}
			else printf("%c",a[i]);
		}
	}
}
