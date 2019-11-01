#include <stdio.h>
#define MAXN 10

int ArrayShift(int a[],int n,int m );

int main()
{
    int a[MAXN], n, m;
    int i;
    printf("请输入元组长度与向右移的位数：\n");
    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a,n,m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}
int ArrayShift(int a[],int n,int m)
{
	int i,j=0;
	

    for(i=m;i<m+n;i++)
    {
    
    
    }

} 
