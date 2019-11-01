#include<stdio.h>
#include<string.h>
int main()
{
    int m,n;
    int b[11];
    scanf("%d%d",&m,&n);
    char a[m][11];
    int i;
    for(i=0;i<m;i++)
      scanf("%s",a[i]);
    int j;
    int change=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m-i-1&&change;j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {
                strcpy(b,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],b);
                change=1;
            }
        }
    }
    for(i=0;i<m;i++)
      puts(a[i]);  
}
