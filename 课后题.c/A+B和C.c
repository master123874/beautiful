#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long int A[n],B[n],C[n];
    int i;
    for(i=0;i<n;i++)
      scanf("%ld%ld%ld",&A[i],&B[i],&C[i]);
    for(i=0;i<n;i++)
    {
        if(A[i]+B[i]>C[i])printf("Case #%d: true",i+1);
        else printf("Case #%d: false",i+1);
    }
}
