#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include<ctype.h>

#include"play.h"

int Play_UI_Modify(int id)
{
	int rtn=0;
	Play_t buf;
	if(Play_Srv_FetchByID(id,&buf)==1)
	{
		printf("---------------------------");
		printf("�������޸ĵ���Ϣ\n");
		printf("�������ĿID:");
		scanf("%d\n",&buf.id);
		printf("�������Ŀ����:");
		scanf("%s",&buf.name);
		printf("�������Ŀ����:");
		scanf("%d\n",&buf.type);
		printf("�������Ŀ��Ʒ����:");
		scanf("%s\n",&buf.area);
		printf("�������Ŀ�ȼ�:");
		scanf("%d\n",&buf.rating);
		printf("�������Ŀʱ��:");
		scanf("%d\n",&buf.duration);
		printf("�������Ŀ���ŷ�ӳ����:");
		scanf("%d-%d-%d\n",&buf.start_date.year,&buf.start_date.month,&buf.start_date.day); 
		printf("�������Ŀ������ӳ����:");
		scanf("%d-%d-%d\n",&buf.end_date.year,&buf.end_date.month,&buf.end_date.day);
		printf("�������ĿƱ��:");
		scanf("%d\n",&buf.price); 
		printf("--------------------------");
		if(Play_Srv_Modify(&buf)==1)
		{
			printf("�޸���Ϣ�ɹ�\n");
			rtn=1;
		}
		else
		{
			printf("�޸���Ϣʧ��\n");
			return 0;
		}
		 
	}
	else
	{
		printf("��ȡ�ݳ��ƻ�ʧ��\n");
		return 0;
	}
	return rtn;
}
int Play_UI_Delete(int id)
{
	int rtn=0;
	if(Play_Srv_DeleteByID(id)==1)
	{
		rtn=1;
		printf("ɾ����Ŀ�ݳ��ƻ��ɹ�\n");
		return rtn;
	}
	else
	{
		printf("ɾ����Ŀ�ݳ��ƻ�ʧ��\n");
		return 0;
	}
}
int Play_UI_Add()
{
	play_t data;
	int newCount=0;
	char choice;
	do
	{
		printf("----------------------------------")
		printf("�������޸ĵ���Ϣ\n");
		printf("�������ĿID:");
		scanf("%d\n",&buf.id);
		printf("�������Ŀ����:");
		scanf("%s",&buf.name);
		printf("�������Ŀ����:");
		scanf("%d\n",&buf.type);
		printf("�������Ŀ��Ʒ����:");
		scanf("%s\n",&buf.area);
		printf("�������Ŀ�ȼ�:");
		scanf("%d\n",&buf.rating);
		printf("�������Ŀʱ��:");
		scanf("%d\n",&buf.duration);
		printf("�������Ŀ���ŷ�ӳ����:");
		scanf("%d-%d-%d\n",&buf.start_date.year,&buf.start_date.month,&buf.start_date.day); 
		printf("�������Ŀ������ӳ����:");
		scanf("%d-%d-%d\n",&buf.end_date.year,&buf.end_date.month,&buf.end_date.day);
		printf("�������ĿƱ��:");
		scanf("%d\n",&buf.price);
		printf("---------------------------------");
		if(Play_Srv_Add(&data)==1)
		{
			printf("����¾�Ŀ�ɹ�\n");
			newCount++; 
			printf("�������Ƿ�������������¾�Ŀ:");
			choice=getchar();
		}
		else
		{
			printf("����¾�Ŀʧ��\n"); 
			return 0;
		}
	}while(choice!='a'||choice!='A');
	
	return newCount;
	
}
int Play_UI_Query(int id)
{
	int rtn=0;
	if(Play_UI_FetchByID(id)==1)
	{
		rtn=1;
		printf("��ѯ��Ŀ����ɹ�");
		return rtn;
	}
	else
	{
		prinf("��ѯ��Ŀ����ʧ��");
		return 0;
	}
}
