#include<stdio.h>
int main()
{
    int t,t1,n;
    float m,temp;
    scanf("%d %f %d",&t,&m,&t1);
    int i,j;
    int s=0,s1=0;
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        int count=0;
        if(n<=10)
        {
            for(j=0;j<n;j++)
            {
                scanf("%f",&temp);
                if(temp<m)count++;
            }
            if(count>n/2)s++;
        }
        else
        {
            for(j=0;j<n;j++)
            {
                scanf("%f",&temp);
                if(temp<m)count++;
            }
            if(count>n/2)s1++;
        }
    }
    printf("%.1f%% %.1f%%",(float)s/t*100,(float)s1/t*100);
}
