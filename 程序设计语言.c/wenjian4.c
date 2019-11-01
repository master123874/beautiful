#include <stdio.h>
#include <ctype.h>
#include <string.h>
void Pack(FILE *src, FILE *dst);

int main()
{
    char sname[1024], dname[1024];
    FILE *sfile, *dfile;

    gets(sname);
    gets(dname);

    sfile = fopen(sname, "rb");
    if (!sfile)
    {
        printf("%s 无法打开!\n", sfile);
    }
    dfile = fopen(dname, "wb");
    if (!dfile)
    {
        printf("%s 无法打开!\n", dfile);
    }
    if (sfile && dfile)
    {
        printf("正在整理...");
        Pack(sfile, dfile);
        puts("整理完成!");
    }
    if (sfile)
    {
        fclose(sfile);
    }
    if (dfile)
    {
        fclose(dfile);
    }
    return 0;
}
void Pack(FILE *src, FILE *dst)
{
	char ch,ch1;
	long i,j;
	char a[4];
	int flag=0;
	while(!feof(src))
	{
		ch=fgetc(src);
		if(ch==EOF)continue;
		i=ftell(src);
		if(ch=='"')
		{
			fputc(ch,dst);
			ch=fgetc(src);
			while(!feof(src))
			{
				fputc(ch,dst);
				ch=fgetc(src);
				if(ch=='"')break;
			}
			fputc(ch,dst);
		}
		else if(ch=='/')
		{
			ch=fgetc(src);
			if(ch=='/')
			{
				ch=fgetc(src);
				while(!feof(src)&&ch!='\n')
				{
					ch=fgetc(src);
				}
				fputc('\n',dst);
			}
			else if(ch=='*')
			{
				fgets(a,2,src);
				fseek(src,-1L,SEEK_CUR);
				while(!strstr(a,"*/")&&!feof(src))
				{
					fgets(a,2,src);
					fseek(src,-1L,SEEK_CUR);
				}
				if(!strstr(a,"*/"))
				{
					j=ftell(src);
					fseek(src,i,j);
					ch=fgetc(src);
					fputc(ch,dst);
				}
				else fputc(' ',dst);
			}
			else
			{
				fseek(src,-2L,SEEK_CUR);
				ch=fgetc(src);
				fputc(ch,dst);
			}
		}
		else fputc(ch,dst);
			
		
		
		
	}
	
	
}
