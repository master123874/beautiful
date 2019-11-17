#include<stdio.h>
#include<math.h>
int getcount(int b)
{
    int count = 0;
    while(b){
        count++;
        b/=10;
    }
    return count;
}
int judge(int a,int b,int c)
{
    int d[10]={0};
    while(b){
        d[b%10]=1;
        b/=10;
    }
    while(a){
        d[a%10]=1;
        a/=10;
    }
    while(c){
        d[c%10]=1;
        c/=10;
    }
    int i;
    for(i=1;i<=9;i++){
        if(!d[i])return 0;
    }
    return 1;
}

int main()
{
    int m,n;
    scanf("%d",&n);
    int i,j;
    int count=0;
    for(i=1;i<n;i++){
        for(j=1;j<=pow(10,9-getcount(i));j++){
            int t=getcount(i);
            int t1=getcount(j);
            int t2=getcount((n-i)*j);
            if(t+t1+t2==9&&judge(t,t1,t2)){
                count++;
            }
        }
    }
    printf("%d",count);
}
