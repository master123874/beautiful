#include<stdio.h>
#define N 10
int main()
{
	int i,a[N],max,t=0;
	for(i=0;i<N;i++)
	  scanf("%d",&a[i]);
	  
	max=a[0];  
	for(i=1;i<N;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			t=i;
		}
		 
	}
	
	printf("�ɼ����Ϊ%d��,ѧ�����Ϊ%d\n",max,t+1);
} 
