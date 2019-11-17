#include<stdio.h>
int sortByMaoPao(int *num,int length)
{
    int i,j;
    int change=1;
    for(i=0;i<length&&change;i++){
        change=0;
        for(j=0;j<length-i-1;j++){
            if(num[j]>num[j+1]){
                int t=num[j];
                num[j]=num[j+1];
                num[j+1]=t;
                change=1;
            }
        }
    }
}
int main()
{
    int a[]={5,3,6,4,8,6,9,5,6};
    int len=sizeof(a)/sizeof(int);
    int i;
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    sortByMaoPao(a,len);
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }

}
