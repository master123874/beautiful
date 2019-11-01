#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    char name[n][11];
    char xh[n][11];
    int score[n];
    int i=0;
    for(;i<n;i++)
      scanf("%s%s%d",name[i],xh[i],&score[i]);
    int max=score[0],t1=0;  
    for(i=1;i<n;i++)
    {
    	if(score[i]>max)
    	{
    		max=score[i];
    		t1=i;
		}
        
    }
    printf("%s %s\n",name[t1],xh[t1]);
    int min=score[0]; 
	int t2=0; 
    for(i=1;i<n;i++)
    {
        if(score[i]<min)
        {
        	min=score[i];
        	t2=i;
		}   
    }
    printf("%s %s",name[t2],xh[t2]);
    

    return 0;

}
