#ifndef Schedule_h
#define Schedule_h

typedef struct{
	int hour;
	int minute;
	int second;
}ttms_time_t;
typedef struct
{
	int id;
	int play_id;
	int studio_id;
	ttms_time_t data;
	ttms_seat_t time;
	int seat_count;
}schedule_t;
typedef struct schedule_node{
	schedule_t data;
	struct schedule_node *next;
	struct schedule_node *prev;
}schedule_node_t,*schedule_list_t;

void Schedule_UI_MgtEntry(int play_id);
int Schedule_UI_Add(int play_id);
int Schedule_UI_Modify(int id);
int Schedule_UI_Delete(int id);
int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id);
int Schedule_Srv_Add(schedule_t *data);
int Schedule_Srv_Modify(const schedule_t *data);
int Schedule_Srv_DeleteByID(int id);
int Schedule_Perst_SelectByPlay(schedule_list_t list,int play_id);
int Schedule_Perst_Insert(schedule_t *data);
int Schedule_Perst_Updata(const schedule_t *data);
int Schedule_Perst_RemByID(int id);

#endif
