#include<stdio.h>
#include<string.h>
#define N 1000
int retu(char *a)
{
    int i;
    for(i=0;i<strlen(a);i++)
        if(a[i]=='i'||a[i]=='o'||a[i]=='a'||a[i]=='e'||a[i]=='u')return i+1;
    return 0;

}
int main()
{
    char a[N];
    gets(a);
    printf("%d",retu(a));
}
