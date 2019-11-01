#include<stdio.h>
#include<stdlib.h>
#include"schedule.h"

int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id)
{
	return Schedule_Perst_SelectByPlay(list,plau_id); 
}
int Schedule_Srv_Add(schedule_t *data)
{
	return Schedule_Perst_Insert(data);
}
int Schedule_Srv_Modify(const schedule_t *data)
{
	return Schedule_Perst_Updata(data);
}
int Schedule_Srv_DeleteByID(int id)
{
	return Schedule_Perst_RemByID(id);
}
