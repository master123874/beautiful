#include<stdio.h>
#define N 8
static int startx,starty;
static int a[N][N];
int cango(int *x,int *y,int flag)
{
	switch(flag)
	{
		case 0:{
			
			if(*x-2>=0&&a[*x-2][*y+1]==0&&*x-2<=N-1&&*y+1>=0&&*y+1<=N-1)
			{
				*x-=2;
				*y+=1;
				return 1;
			}
			break;    
		}
		case 1:{
			if(*x-1>=0&&a[*x-1][*y+2]==0&&*x-1<=N-1&&*y+2>=0&&*y+2<=N-1)
			{
				*x-=1;
				*y+=2;
				return 1;
			}
			break; 
		}
		case 2:{
			
			if(*x+1>=0&&a[*x+1][*y+2]==0&&*x+1<=N-1&&*y+2>=0&&*y+2<=N-1)
			{
				*x+=1;
				*y+=2;
				return 1;
			}
			break;   
		}
		case 3:{
			if(*x-2>=0&&a[*x-2][*y+1]==0&&*x-2<=N-1&&*y+1>=0&&*y+1<=N-1)
			{
				*x-=2;
				*y+=1;
				return 1;
			}
			break;
		}
		case 4:{
			if(*x+2>=0&&a[*x+2][*y-1]==0&&*x+2<=N-1&&*y-1>=0&&*y-1<=N-1)
			{
				*x+=2;
				*y-=1;
				return 1;
			}
			break;
		}
		case 5:{
			if(*x+1>=0&&a[*x+1][*y-2]==0&&*x+1<=N-1&&*y-2>=0&&*y-2<=N-1)
			{
				*x+=1;
				*y-=2;
				return 1;
			}
			break;   
		}
		case 6:{
			
			if(*x-1>=0&&a[*x-1][*y-2]==0&&*x-1<=N-1&&*y-2>=0&&*y-2<=N-1)
			{
				*x-=1;
				*y-=2;
				
				return 1;
			}
			break;  
		}
		case 7:{
			
			if(*x-2>=1&&a[*x-2][*y-1]==0&&*x-2<=N&&*y-1>=1&&*y-1<=N)
			{
				*x-=2;
				*y-=1;
				return 1;
			}
			break;    
		}
		default: break;
	}
	return 0;
}
int dfs(int startx,int starty,int com)
{
	int count=0,x1=startx,x2=starty;
	a[startx][starty]=com;
	if(com==N*N)
		return 1;
	int flag=0;
	flag=cango(&x1,&x2,count);
	while(flag==0&&count<7)
	{
		count++;
		flag=cango(&x1,&x2,count);
	}	
	while(flag)
	{
		if(dfs(x1,x2,com+1)) return 1;
		x1=startx;
		x2=starty;
		count+=1;
		flag=cango(&x1,&x2,count);
		while(flag==0&&count<7)
		{
			count++;
			flag=cango(&x1,&x2,count);
		}
	}
	if(!flag) a[startx][starty]=0;
	return 0;
	
	
}
int main()
{
	scanf("%d %d",&startx,&starty);
	int i,j;
	for(i=0;i<N;i++)
	  for(j=0;j<N;j++)
	    a[i][j]=0;
	if(dfs(startx-1,starty-1,1))
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
		  		printf("%2d ",a[i][j]);
			printf("\n");  
		}  
	}
	
}
