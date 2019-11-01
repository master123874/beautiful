#include<stdio.h>
#include<stdlib.h>

#include"schedule.h"

int Schedule_Srv_FetchAll(schedule_list_t list)
{
	int rtn;
	rtn=Schedule_Perst_SelectAll(list);
	return rtn;
}
int Play_Srv_FetchByName(play_list_t list,char condt[])
{
	return Play_Perst_SelectByName(list,condt);
}

