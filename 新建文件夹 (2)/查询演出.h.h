#ifndef S_h
#define S_h

void Schedule_UI_ListAll();

int Schedule_UI_Query(char *play_name);

int Schedule_Srv_FetchAll(schedule_list_t list);

int Play_Srv_FetchByName(play_list_t list,char condt[]);

int Schedule_Perst_SelectAll(schedule_list_t list);

int Play_Perst_SelectByName(play_list_t list,char condt[]);

#endif

