#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    char a[10];
    int i;
    for(i=0;i<n;i++)a[i]='z';
    a[i]='\0';
    scanf("%d",&m);
    int t=n;
    while(m){
        if(m%26==0){
            a[n-1]='a';
            m/=26;
        }
        else{
            a[n-1]=a[n-1]-m%26+1;
            m/=26;
        }
        n--;
    }
    for(i=n;i<t-1;i++)a[i]=a[i]-1;
    printf("%s",a);
}
