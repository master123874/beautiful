#include <stdio.h>
#include <stdlib.h>


void WriteLetter(FILE *f, int n);

int main()
{
    FILE *f;
    int n;
    f = fopen("Letter.txt", "w");
    if (!f)
    {
        puts("文件无法打开!");
        exit(1);
    }

    scanf("%d", &n);
    WriteLetter(f, n);

    if (!fclose(f))
    {
        puts("文件无法关闭!");
        exit(1);
    }
    puts("文件保存成功!");
    return 0;
}
void WriteLetter(FILE *f, int n)
{
	int i;
	char ch;
	for(i=0;i<n;i++)
	{
		scanf("%c",ch);
		fputc(ch,f);
	}
}

