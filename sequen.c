 typedef BiTree LQeletype;
/*队列结点类型*/
typedef struct LinkedQueueNode
{
LQeletype data;
struct LinkedQueueNode *next;
}LQN,*LQueueNode;
/*队列指针类型*/
typedef struct {
LQueueNode front;
LQueueNode rear;
}LQ,*LQueue;

/*初始化*/
LQueue Init_LinkdedQueue()
{
LQueue Q=(LQueue)malloc(sizeof(LQ));
LQN *head=(LQueueNode)malloc(sizeof(LQN));
head->next=NULL;
Q->front=head;
Q->rear=head;
return Q;
}
/* 判空*/
int LinkedQueue_Empty(LQueue Q)
{
return Q->front==Q->rear;
}
/* 入队*/
int Enter_LinkedQueue(LQueue Q,LQeletype data)
{
LQueueNode node;
node=(LQueueNode)malloc(sizeof(LQN));
if(!node)
{
return 0;
}
node->data=data;
node->next=NULL;
Q->rear->next=node;
Q->rear=node;
return 1;
}

/*出队*/

int Delete_LinkedQueue(LQueue Q,LQeletype *data)
{
LQueueNode f;
if(LinkedQueue_Empty(Q))
{
printf("LinkedQueue empty!\n");
return 0;
}
else
{
f=Q->front->next;
*data=f->data;
Q->front->next=f->next;
if(f==Q->rear)
Q->rear=Q->front;
   return 1;
}
}
/* 清空队列*/
int Clear_LinkedQueue(LQueue Q,LQeletype *data)
{
while(Delete_LinkedQueue(Q,data));
return 1;
}
/* 释放队列*/
int free_LinkedQueue(LQueue Q,LQeletype *data)
{
Clear_LinkedQueue(Q,data);
free(Q->rear);
free(Q->front);
free(Q);
return 1;
}