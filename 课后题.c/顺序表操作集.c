#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; 
};
List MakeEmpty()
{
    List L = NULL;
    L= (struct LNode*) malloc( sizeof(struct LNode));
    if(L == NULL)
        return NULL;
    L ->Last = 0;
    return L;
}
Position Find(List L, ElementType X)
{
    int res = ERROR;
    int i = 0;
    if(L == NULL)
        return ERROR;
    while(i < MAXSIZE)
    {
        if(L ->Data[i] == X)
        {
            res = i;
            break;
        }
        i++;
    }
    return res;
}
bool Insert(List L, ElementType X, Position P)
{
    int tmpLast = L ->Last;
    bool res = true;
    if(L->Last >= MAXSIZE || L == NULL)
    {
        printf("FULL");
         res = false;
        return res;
    }
    if(P < 0 || P > L ->Last )
    {
        printf("ILLEGAL POSITION");
        res = false;
        return res;
    }
    if(P + 1 == MAXSIZE)
    {
        L ->Data[P] = X;
        (L ->Last)++;
    }    
    else
    {
        while(tmpLast > P)
        {
            L ->Data[tmpLast] = L ->Data[tmpLast -1];
            tmpLast--;
        }
        L ->Data[P] = X;
        (L ->Last)++;
    }
    return res;
}
bool Delete(List L, Position P)
{
    bool res = true;
    if(P < 0 ||  P >= L->Last)
    {
        res = false;
        printf("POSITION %d EMPTY", P);
        return res;
    }
    while(P < ( L ->Last -1 ))
    {
        L ->Data[P] = L ->Data[P + 1];
        P++;
    }
    (L ->Last)--;
    return res;
}
int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
