#include<stdio.h>
#include<math.h> 
typedef struct{
	int x,y;
}S;
int main()
{
	int n;
	scanf("%d",&n);
	S a[n],b[n];
	int i,j,count=0;
	int flag;
	for(i=0;i<n;i++)a[i].y=1;
	for(i=0;i<n;i++)scanf("%d",&a[i].x);
	for(i=0;i<n;i++)
	{
		flag=0;
		if(a[i].x!=-1)
		{
			a[i].x=abs(a[i].x-i-1);
			for(j=i+1;j<n;j++)
			{
				if(a[j].x!=-1)
				{
					if(abs(a[j].x-j-1)==a[i].x)
					{
						a[j].x=-1;
						a[i].y++;
						flag=1;
					}
				}	
			}	
			if(flag)b[count++]=a[i];
		}
			
	}
	S t;
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(b[j].x>b[i].x)
			{
				t=b[j];
				b[j]=b[i];
				b[i]=t;
			}
		}
	}
	for(i=0;i<count;i++)
		printf("%d %d\n",b[i].x,b[i].y);
}
