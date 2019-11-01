#include <stdio.h>
#include <stdlib.h>
void WriteArticle(FILE *f);

int main()
{
    FILE *f;
    f = fopen("d:/英雄时刻/article.txt", "w");
    if (!f)
    {
        puts("文件无法打开!");
        exit(1);
    }
    WriteArticle(f);

    fclose(f);
    puts("文件保存成功!");
    return 0;
}
void WriteArticle(FILE *f)
{
	char ch; 
	while((ch=getchar())!=EOF)
	{
		fputc(ch,f);
	}
}
