
#include <stdio.h>
int main(void){
    int a[54]={1,2,3,4},n,i;
    for(i=4;i<54;i++)
        a[i]=a[i-1]+a[i-3];
    scanf("%d",&n);
    while(n!=0){
        printf("%d\n",a[n-1]);
        scanf("%d",&n);
    }
    return 0;
}
