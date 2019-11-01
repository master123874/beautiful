#include<stdio.h>  
int main()  
{  
    double x;  
    double i = 2, d = 3;//i从第二项开始，d为第二项分母  
    double temp=1,n = 1, n1 = 2, sum = 1;  
    scanf("%lf", &x);
    while (temp >= x)  
    {  
        temp = n / d;//每一项的单项  
        sum += temp;
        n = n*n1;//分子  
        n1++;  
        d = d*(2 * i + 1);//分母 
        i++;  
    }  
    printf("%.6f\n", sum*2); 
    return 0;  
}
