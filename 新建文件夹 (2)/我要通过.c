#include<stdio.h>
void print(char *a[10])
{
	int i;
	for(i=0;i<3;i++)printf("%s ",a[i]);
}

int main()
{
	char a[3][10]={"change","dasd","fdsf"};
	print(a);
}
