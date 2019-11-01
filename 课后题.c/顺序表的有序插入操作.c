
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;
void InitList(SqList *L)
{
	L->length=0;
	L->elem=(ElemType *)malloc(MAXSIZE*sizeof(int));
}
int SqInsert(SqList *L,ElemType e)
{
    if(e>MAXSIZE)return 0;
    L->length=e;
    L->elem[0]=e;
    int i,t,j;
    for(i=1;i<e;i++)
    {
        scanf("%d",&t);
        if(t==-1)
        {
            scanf("%d",&t);
            if(t<=L->elem[0])
            {
                for(j=i-1;j>=0;j--)L->elem[j+1]=L->elem[j];
                L->elem[0]=t;
            }
            else if(t>=L->elem[i-1])
            {
                L->elem[i]=t;
            }
            else
            {
                int x;
                for(j=0;j<i-1;j++)
                {
                    if(t>=L->elem[j]&&t<=L->elem[j+1])
                    {
                        x=j+1;
                        break;
                    }
                }
                for(j=x;j<i;j++)L->elem[j+1]=L->elem[j];
                L->elem[x]=t;
            }
        }
        else
        {
            L->elem[i]=t;
        }
    }

    return 1;

}
int main()
{
	SqList L;
	InitList(&L);
	ElemType e;
	int j;
	scanf("%d",&e);
	int result=SqInsert(&L,e);
	if(result==0){
		printf("Insertion Error.The storage space is full!");	
	}else if(result==1){
		printf("Insertion Success.The elements of the SequenceList L are:");	
		for(j=0;j<L.length;j++){
			printf(" %d",L.elem[j]);
		}
	}
	return 0;
}
