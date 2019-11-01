#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 81
int judge(char ch,char *b)
{
    int flag=0;
    int i;
    for(i=0;i<strlen(b);i++)
    {
        if(tolower(b[i])==tolower(ch))return 0;
    }
    return 1;

}
int main()
{
    char a[N],b[N];
    gets(a);
    gets(b);
    int i,j;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]!=-1)
        {
            for(j=i+1;j<strlen(a);j++)
            {
                if(toupper(a[i])==toupper(a[j]))a[j]=-1;
            }
        }
    }
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]!=-1)
        {
            if(judge(a[i],b))printf("%c",toupper(a[i]));
        }
    }
}
