#include<stdio.h>
int main()
{
    long int a,b,c=1;
    long s=0,s1;
    scanf("%ld%ld",&a,&b);
    s1=a;
    if(a>=1&&a<=9&&b>=0&&b<=100000)
    {
        while(c<=b)
        

      {
        s+=s1;
        s1+=a*10;
        a*=10;
        c++;
      }
    }
    printf("%ld",s);

}
