#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}
int IsTheNumber ( const int N )
{
	int count=0;
	int t=N;
	int a[10];
	while(t>0)
	{
		a[count]=t%10;
		count++;
		t/=10;
	}
	int i,j;
	int count1[count];
	for(i=0;i<count;i++)count1[i]=1;
	for(i=0;i<count-1;i++)
	{
        if(a[i]!=-1)
		{
            for(j=i+1;j<count;j++)
              if(a[i]==a[j])
              {
                  a[j]=-1;
                  count1[i]++;
              }
		}
	}
	int max=count1[0];
	for(i=1;i<count;i++)
	  if(count1[i]>max)max=count1[i];
	if(max>=2&&sqrt(N)==(int)sqrt(N))return 1;
	return 0;  
	
}
