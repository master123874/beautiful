#include<stdio.h>
void insertsort(int *num,int n)
{
    int i,j;
    for(i=1;i<n;i++){
        int t=num[i];
        j=i-1;
        while(j>=0&&t<num[j]){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=t;
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
    insertsort(a,len);
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }

}
