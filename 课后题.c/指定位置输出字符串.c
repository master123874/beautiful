#include <stdio.h>
#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}
char *match( char *s, char ch1, char ch2 ){

	char *p1=s,*p2;

	while(*p1!='\0'&&*p1!=ch1){

		p1++;
	}
	p2=p1;
	if(*p2==ch2)
	{
		printf("%c\n",ch2);
		return p2;
	}
	while(*p2!='\0'&&*p2!=ch2)
	{
		printf("%c",*p2++);
		
	}
	if(*p2==ch2){
			printf("%c\n",ch2);
		
		}
	else printf("\n");	
	return p1;

}
