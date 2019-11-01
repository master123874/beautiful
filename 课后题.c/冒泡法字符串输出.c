#include<stdio.h>
#include<string.h>
#define N 10
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    char a[n][10];
    char c[10];
    int i,j,d;
    for(i=0;i<n;i++)
      scanf("%s",&a[i]);
    for(i=1;i<=k;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {  
                for(d=0;d<10;d++)
                {
                    if(a[j]) c[d]=a[j][d];
                    else break;
                }
                for(d=0;d<10;d++) 
                {    
                    if(a[j+1][d])
                        a[j][d]=a[j+1][d]; 
                    else break;    
                }
                for(d=0;d<10;d++) 
				{
					if(c[d]) a[j+1][d]=c[d];
					else break;
			    }
			    for(d=0;d<10;d++) c[d]='\0';
				       
            } 
        }
    }
    for(i=0;i<n;i++)
      printf("%s\n",a[i]);
    return 0;  

}
