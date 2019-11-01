#include <stdio.h>

void Print_Factorial (const int N);

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial(const int N)
{
	int a=N;
	long double s=1;
	int i;
	if(N<0)printf("Invalid input\n");
	else
	{
		for(i=1;i<=a;i++)
		{
			s*=i;
		}
		printf("%.lf",s);
	} 
}

