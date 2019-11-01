#include<stdio.h>
#include<string.h>
int main()
{
    char a[20][10];
    int b=0;
    char c[10],ch;
    while(b<=20)
    {
        scanf("%s",a[b]);
        if(strcmp("#",a[b])==0) break;
        b++;   
    }
    int i,j;
    for(i=0;i<b;i++)
    {
        for(j=i+1;j<b;j++)
        {
            if(strlen(a[i])>strlen(a[j]))
            {
                strcpy(c,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],c);
            }  
        }
    }
    for(i=0;i<b;i++)
      printf("%s ",a[i]);
}
