#include<stdio.h>
int main()
{
    int i=0,j;
    int a[20];
    float ave,s=0;
    for(i=0;i<20;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<0)break;
		else s+=a[i];
		
	} 
    ave=s/i;
    printf("%.2f\n",ave);
    for(j=0;j<i;j++)
    {
        if(a[j]<ave)
          printf("%6.1f",(float)a[j]);
    }
    
}
