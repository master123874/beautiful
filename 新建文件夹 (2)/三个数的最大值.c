#include<stdio.h>
#include<stdlib.h>
int maximumProduct(int* nums, int numsSize)
{
	int i,j,k;
	int flag=1;
	int max,max1;
	int t;
	for(i=0;i<numsSize-1&&flag;i++)
	{
		flag=0;
		for(j=0;j<numsSize-i-1;j++)
		{
			if(nums[j]>nums[j+1])
			{
				int t=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=t;
				flag=1;
			}
		}
	}
	for(i=0;i<numsSize;i++)printf("%d\n",nums[i]);
	max=nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
	max1=nums[numsSize-1]*nums[0]*nums[1];
	return max>max1?max:max1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	printf("%d",maximumProduct(a,n));
}
