#include<stdio.h>
#include<string.h>
#include"List.h"
#include"ticket.h"

void Ticket_UI_MgtEntry(int schedule_id)
{
	schedule_t buf;
	play_t data;
	char choice; 
	if(Schedule_Srv_FetchByID(schedule_id,&buf)==1)
	{
		printf("��ȡ�ݳ��ƻ��ɹ�\n");
		if(Play_Srv_FetchByID(buf.play_id,&data)==1)
		{
			printf("��ȡ��Ŀ��Ϣ�ɹ�");
			printf("���������ѡ��a/A:�����ݳ�Ʊ,b/B:��������Ʊ:");
			scanf("%c",&choice);
			switch(choice)
			{
				case 'a':
				case 'A':{
					if(Ticket_Srv_GenBatch(buf.id)>=0)
					{
						printf("\t\t\t����Ʊ�����ɹ�\n");
						printf("\t\t\t��Ŀ����    �ݳ���ID     �ݳ�����      �ݳ�ʱ��\n");
						printf("\t\t\t%s       %4d         %04d-%02d-%02d       %02d:%02d:%02d",data.name,buf.studio_id,buf.date.year,buf.date.month,buf.date.day,buf.time.hour,buf.time.minute,buf.time.second);
						
					else
					{
						printf("����Ʊ����ʧ��");
					}
					break;
				} 
				case 'B':
				case 'b':{
					if(Ticket_Srv_DeleteBatch(buf.id)>=0)
					{
						printf("�����ɹ�\n");
						if(Ticket_Srv_GenBatch(buf.id)==0)
						{
							printf("�Ѿ���ӡ��,�޷��ٴδ�ӡ");
						}
						
						
					}
					else
					{
						printf("����ʧ��\n");
					}
					break;
				} 
				default:printf("�޶�Ӧ��ѡ��\n");break;
				
			}
		}
		
	}
	else
	{
		printf("��ȡ�ݳ��ƻ�ʧ��\n");
		return;
	}
}

