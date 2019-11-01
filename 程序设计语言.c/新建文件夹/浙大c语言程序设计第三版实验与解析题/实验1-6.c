#include<stdio.h>
#include<stdlib.h>
#define Pi 3.1415926535
int main()
{
  int n;
  double r,h;
  while(1)
  {
    scanf("%d",&n);
    printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n"); 
    switch(n)
    {
      case 1:{
        printf("Please enter the radius:\n");
        scanf("%lf",&r);
        printf("%.2f\n",r*r*r/3*Pi*4);
        break;
      }
      case 2:{
        printf("Please enter the radius and the height:\n");
        scanf("%lf%lf",&r,&h);
        printf("%.2f\n",Pi*r*r*h);
        break;
      }
      case 3:{
        printf("Please enter the radius and the height:\n");
        scanf("%lf%lf",&r,&h);
        printf("%.2f\n",r*r/3*Pi*h);
        break;
      }
      default:exit(0);
        
      
    }

  }
  
  return 0;
  
  
  
}
