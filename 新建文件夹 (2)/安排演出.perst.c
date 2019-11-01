#include<stdio.h>
#include<stdlib.h>
#include"schedule.h"

int Schedule_Perst_SelectByplay(schedule_list_t list,int play_id)
{
	int recCount=0;
	FILE *fp;
	fp=fopen("Schedule.dat","rb");
	if(fp==NULL)
	{
		printf("%s打开失败","Schedule.dat");
		return recCount;
	}
	schedule_t *data;
	schedule_list_t ptemp=list;
	while(!feof(fp))
	{
		fread(data,sizeof(schedule_t),1,fp);
		if(data.play_id==play_id)
		{
			ptemp->data=temp;
			ptemp=ptemp->next; 
			recCount++;
		}
	}
	fclose(fp);
	return recCount;	
}
int Schedule_Perst_Insert(schedule_t *data)
{
	FILE *fp;
	int flag=0;
	fp=fopen("Schedule_t","ab+")
	if(!fp)
	{
		printf("%s无法正常打开","Schedule_dat");
		return 0;
	}
	if(fwrite(data,sizeof(schedule_t),1,fp)>=1)
	{
		flag=1;
	}
	fclose(fp);
	return flag;
}
int Schedule_Perst_Update(const schedule_t *data)
{
	FILE *fp;
	int found=0;
	fp=fopen("Schedule_dat","ab");
	if(!fp)
	{
		printf("%s无法正常打开","Schedule_dat");
		return 0;
	}
	schedule_t buf;
	int i;
	while(!feof(fp))
	{
		i=ftell(fp);
		fread(&buf,sizeof(scedule_t),1,fp);
		if(buf.id==data->id)
		{
			found=1;
			fseek(fp,i,SEEK_CUR);
			fwrite(data,sizeof(scedule_t),1,fp);
		}
	}
	fclose(fp);
	return found;
}
int Schedule_Perst_RemByID(int id)
{
	FILE fp,fp1;
	char ch;
	int a=rename("Schedule.dat","ScheduleTmp.dat");
	if(a==1)
	{
		printf("文件名修改失败");
		return 0; 
	}
	fp=fopen("Schedule.dat","wb+");
	fp1=fopen("ScheduleTmp.dat","rb+");
	if(fp==NULL)
	{
		printf("%s打开失败","Schedule.dat");
		return 0;
	}
	if(fp1==NULL)
	{
		printf("%s打开失败","Scheduletmp.dat");
		return 0;
	}
	while(!feof(fp))
	{
		ch=fgetc(fp);
		fputc(ch,fp1);
	}
	rewind(fp);
	rewind(fp1);
	int found=0;
	schedule_t buf;
	while(!feof(fp1))
	{
		fread(&buf,sizeof(schedule_t),1,fp1);
		if(buf.id==id)found=1;
		fwrite(&buf,sizeof(schedule_t),1,fp);
	}
	fclose(fp);
	fclose(fp1);
	remove("ScheduleTmp.dat");
	return found;
}
