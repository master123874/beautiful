#include <stdio.h>
#include <stdlib.h>
void WriteArticle(FILE *f);

int main()
{
    FILE *f;
    f = fopen("d:/Ӣ��ʱ��/article.txt", "w");
    if (!f)
    {
        puts("�ļ��޷���!");
        exit(1);
    }
    WriteArticle(f);

    fclose(f);
    puts("�ļ�����ɹ�!");
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
