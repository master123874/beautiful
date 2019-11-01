#include<stdio.h>
int i;
int count;
int a[100];
void split(unsigned long n)
{
    while(n>0)
    {
        a[i]=n%10;
        i++;
        count++;
        n/=10;
    }
}
int search(int c)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(c==a[j]) return 1;
    }
    return 0;
}
void output(unsigned long n,unsigned long a)
{
    int count1=0;
    int w=0;
    while(a>0)
    {
        if(search(a%10))
          count1++;
        w++;  
        a/=10;  
    }
    if(count1==w)printf("Yes\n");
    else printf("No\n");
}
int main()
{
    unsigned long n;
    scanf("%lu",&n);
    unsigned long a=2*n;
    split(n);
    output(n,a);
    printf("%lu",a);
}
