#include<stdio.h>
#include<string.h>
#define N 10
#define M 1000
int main()
{
    static int a[N];
    char b[M];
    scanf("%s",b);
    int i;
    for(i=0;i<strlen(b);i++)
    {
        switch(b[i]-48)
        {
            case 0:a[0]++;break;
            case 1:a[1]++;break;
            case 2:a[2]++;break;
            case 3:a[3]++;break;
            case 4:a[4]++;break;
            case 5:a[5]++;break;
            case 6:a[6]++;break;
            case 7:a[7]++;break;
            case 8:a[8]++;break;
            case 9:a[9]++;break;
        }
    }
    for(i=0;i<10;i++)
    {
        if(a[i]!=0)
        {
            printf("%d:%d\n",i,a[i]);
        }
    }

    return 0;

}
