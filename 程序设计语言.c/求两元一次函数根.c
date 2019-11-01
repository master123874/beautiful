#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,disc;
	scanf("%lf%lf%lf",&a,&b,&c);
	disc=b*b-4*a*c;
	if(disc==0&&a==0&&b==0&&c==0)printf("Zero Equation");
	else if(disc==0&&a==0&&b==0&&c!=0)printf("Not An Equation");
	else if(disc>0&&a!=0&&b!=0&&c!=0)printf("%.2f\n%.2f",(-b+sqrt(disc))/(2*a),(-b-sqrt(disc))/(2*a));
	else if(disc>0&&a==0&&b!=0&&c!=0)printf("%.2f",-c/b);
	else if(disc==0)printf("%.2f",-b/(2*a));
	else if(disc<0)printf("%.2f+%.2fi\n%.2f-%.2fi",-b/(2*a),sqrt(-disc)/(2*a),-b/2*a,sqrt(-disc)/(2*a));
	
	return 0; 
	

  
}
