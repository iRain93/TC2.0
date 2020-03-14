#include"stdio.h"
#include 
#include 
#define XY(y) ((y*2-1)*10)   /* 圆心坐标*/
#define X(x) ((x*2-1)*10-7)   /* 圆心坐标*/
#define Y(y) ((y*2-1)*10)   /* 圆心坐标*/

#define R 10                 /* 圆半径*/
#define CHXY(x) ((x-1)*20+7) /* 字符坐标*/
#define CHX(x) ((x-1)*20+7-7) /* 字符坐标*/
#define CHY(y) ((y-1)*20+7) /* 字符坐标*/

#define length 60            /* 数组长度*/
typedef char eletype;
typedef struct BiTreenode{
eletype data;
struct BiTreenode *parent,*lchild,*rchild;
int x,y;
struct BiTreenode *pre,*next;     /*前驱指针和后继指针*/
}BiTreeNode,*BiTree;
#include"sequen.c"
typedef struct TreeData
{
char color; /* 结点的颜色 */
char c;     /* 结点数据   */
int x;      /* 屏幕横坐标 */
int y;      /* 屏幕纵坐标 */
}TreeArray;
static TreeArray a[60];      /*数组*/
int i=0;
int j=0;
int i1=0;
char a2[70];
char *str=NULL;   /*先序列字符串指针*/
int i3=0;
BiTreeNode *fb=NULL;
BiTree pretag=NULL;

/*1第一阶段:关于二叉树的算法*/
void CreateBiTree_2(BiTree *bt,char *str);                         /*使用二叉链表创建二叉树*/
void printf_tree(BiTreeNode *bt);                                  /*打印二叉树*/
int CreateBiTree_3(BiTree *bt,char str[]);                         /*使用三叉链表创建二叉树*/
void PreOrder(int k,BiTreeNode *bt,int x1,int y1,int i);           /* 先序遍历存储二叉树的所有结点 */
void InOrder(int k,BiTreeNode *bt,int x1,int y1);                  /* 中序遍历存储二叉树的所有结点*/
void PostOrder(int k,BiTreeNode *bt,int x1,int y1);                /*后序遍历存储二叉树的所有结点*/
void Memory_xy(BiTree *bt,int x1,int y1);
void Memory_TreePiont(TreeArray a[],BiTreeNode *bt,int x1,int y1); /*存储所有二叉树的结点在数组a[]中*/
int BiTreeDepth(BiTreeNode *bt);                                   /* 求二叉树的深度*/
int max(int i,int j);
void Find_TreePiont_Delay(TreeArray a[],char fch);                 /*查找二叉树的任意结点并显示过程*/
void Traversr_Leaf(BiTreeNode *bt);                                /* 查找叶子结点并显示*/
void DeleteTreePiont(BiTree *bt,char ch,char ceng,char flag);  /*删除二叉树的结点*/
int Clear_Tree(BiTree *bt);                                    /*清除二叉树*/
void Insert_TreePiont(BiTree *bt,BiTreeNode *node,char ch,char rl,char ceng,char flag);   /*插入结点*/
BiTreeNode *Malloc_node(char ch);                                   /*定义一个结点*/
void InThreading(BiTreeNode *p);
void PreThreading(BiTreeNode *p);
void PosThreading(BiTreeNode *p);
int Thrtree(BiTree *head,BiTreeNode *bt,int i);                        /*线索化*/
void printf_thread(BiTreeNode *head);

/*2第二阶段：图形界面画二叉树*/
void GraphInit();
void Draw_TreePiont_One(char fill,char border,char charcolor,char ch,int x,int y);             /*画一个结点*/
void Draw_TreeLine_One(BiTreeNode *bt,char color);                                             /*画一条线*/
void No_See_Tree(BiTreeNode *bt);                                                              /*不可见的二叉树*/
void Draw_TreeLine_Init(BiTreeNode *bt,char color);                                            /*二叉树树干初始化*/
void Draw_TreePiont_Init(BiTreeNode *bt,char fill,char border,char charcolor);                 /*二叉树结点初始化*/
void Show_Tree(BiTreeNode *bt,char threadcolor,char fill,char border,char charcolor,int i);    /*显示二叉树*/
void row(int starty,int startx,int endx,int l,char color);
void col(int startx,int starty,int endy,int l,char color);
int printf_text(char *ch,char x,char y,char color);
void Inita2();

/*第3阶段：功能集成模块*/
char *Current_Path();                                          /*取得当前工作路径，路径以字符串的形式返回*/
void InitArray(TreeArray a[]);                                 /*数组初始化*/
void print(TreeArray a[]);                                     /*打印数组 */
void clear_pingmu(char color);                                 /*清除屏幕*/
void Draw_TreeLine_PIP_Delay(TreeArray a[],int i,char color);
void Tree_high(BiTreeNode *bt,char color);
char *Command_Input(char clearcolor);   /*命令输入*/
int String_compare(char *p);            /*确定命令的正确与否*/
void cursor(char color,int x,int y);
int space(char *p);
void clear_Command(char color);
void Massge_clear();
void blackboard();
int PIP_Tree(BiTreeNode *bt,char c);
int Find_Tree(BiTreeNode *bt,char *input);
int help_command();

void main(int argc,char *args[])
{
FILE *fp;
char text[80];
BiTreeNode *bt=NULL;   /*二叉树根结点指针*/
    BiTreeNode *node=NULL;
BiTreeNode *head=NULL;
char *input=NULL;
int m=100;

/*读入文件*/
Current_Path();
fp = fopen(args[1],"r");
fgets(text,80,fp);
str=text;
fclose(fp);
fp=NULL;
GraphInit();             /*图形初始化*/
CreateBiTree_3(&bt,str); /*创建二叉树*/
blackboard();
if(BiTreeDepth(bt)>=6)
{
Clear_Tree(&bt);                                    /*清除二叉树*/
printf_text("Binary tree create failed!",2,2,14); 
}
/*主菜单结构区域*/
 
while(8)
{
Show_Tree(bt,14,1,2,4,1);
input=Command_Input(0);
m=String_compare(input);
switch(m)
{
case 0: 
PIP_Tree(bt,1);
Thrtree(&head,bt,1);
break;
case 1: 
PIP_Tree(bt,2);
Thrtree(&head,bt,2);
break;
case 2: 
PIP_Tree(bt,3);
Thrtree(&head,bt,3);
break;
case 3: 
Inita2();
i1=0;
Traversr_Leaf(bt);  
printf_text("tree leaf:",2,2,14);
printf_text(a2,6,2,14);
getch();
Massge_clear();
break;
case 4:
Inita2();
i1=0;
i3=0;
DeleteTreePiont(&bt,input[4],input[6],input[8]); 
printf_text(" delete:",2,2,14);
printf_text(a2,6,2,14);
getch();
Massge_clear();
if(BiTreeDepth(bt)==0)
{
printf_text("The current tree does not exist !",2,2,14);
printf_text("Do you want to create ?  Please enter the command create recovery .",2,3,14);
}
break;
case 5:
Find_Tree(bt,input);
getch();
break;
case 6:
node=Malloc_node(input[9]);
i3=0;
Massge_clear();
Insert_TreePiont(&bt,node,input[7],input[11],input[13],input[15]); 
clear_pingmu(0);
break;
case 7: 
Tree_high(bt,4);
getch();
Tree_high(bt,0);
break;
case 8: 
if(BiTreeDepth(bt)==0)
{
Massge_clear();
printf_text("Preorder create:",2,2,14);
i=0;
j=0;
printf_text(str,10,2,14);
CreateBiTree_3(&bt,str); 
getch();
Massge_clear();
}
else
{
printf_text("No create:",2,2,14);
}
break;
case 9:
help_command();
break;
case 10: 
printf_text("Free tree. please wait!",2,2,14);
i1=0;
Clear_Tree(&bt);
bt=NULL;
input=NULL;
head=NULL;
str=NULL;
fb=NULL;
pretag=NULL;
getch();
closegraph();
exit(0);
break;
default:
printf_text(input,2,2,14);
getch();
Massge_clear();
}
*input='\0';
input=NULL;
m=100;
} 
}

void CreateBiTree_2(BiTree *bt,char *str)
{
char ch='\0';
ch=str[i++];
if(ch=='.')
{
*bt=(BiTreeNode *)malloc(sizeof(BiTreeNode));
(*bt)->data=ch;
(*bt)->x=-1;
(*bt)->y=-1;
*bt=NULL;
}
else if(97<=ch&&ch<=122&&j!=1)
{
*bt=(BiTreeNode *)malloc(sizeof(BiTreeNode));
(*bt)->data=ch;
(*bt)->x=-1;
(*bt)->y=-1;
CreateBiTree_2(&((*bt)->lchild),str);
CreateBiTree_2(&((*bt)->rchild),str);
}
else
{
j=1;
*bt=NULL;
}
}

void printf_tree(BiTreeNode *bt)
{
if(bt!=NULL)
{
printf("bt=%x  bt->data=%c\tbt->parent=%x     bt->lchild=%x    bt->rchild=%x\n",bt,bt->data,bt->parent,bt->lchild,bt->rchild);
printf("bt->x=%d bt->y=%d\n",bt->x,bt->y);
printf_tree(bt->lchild);
printf_tree(bt->rchild);
}
}

 /*使用三叉链表创建二叉树*/
int CreateBiTree_3(BiTree *bt,char str[])
{
LQeletype p;
    LQueue Q;
i=0;
CreateBiTree_2(bt,str);         /*创建二叉树，还没有确定结点的父母*/
if((*bt)!=NULL)
{
(*bt)->parent=NULL;
Q=Init_LinkdedQueue();      /*初始化队列*/
p=(*bt);
Enter_LinkedQueue(Q,p);     /* 入队*/
}
while(!LinkedQueue_Empty(Q))
{
Delete_LinkedQueue(Q,&p);
if(!(p->lchild==NULL))
{
p->lchild->parent=p;
Enter_LinkedQueue(Q,p->lchild);  /* 入队*/
}
if(!(p->rchild==NULL))
{
p->rchild->parent=p;
Enter_LinkedQueue(Q,p->rchild);  /* 入队*/
}
}
return 1;
}
/* 先序遍历存储二叉树的所有结点 */
void PreOrder(int k,BiTreeNode *bt,int x1,int y1,int i)
{
if(bt!=NULL)
{
if(i==1)
{
Memory_xy(&bt,x1,y1);            /* 为画线做准备*/
}
Memory_TreePiont(a,bt,x1,y1);     /*存储二叉树所有结点的坐标 在数组a[]中*/
PreOrder(k/2,bt->lchild,x1-k,y1+4,i);
PreOrder(k/2,bt->rchild,x1+k,y1+4,i);
}
}
/* 中序遍历存储二叉树的所有结点*/
void InOrder(int k,BiTreeNode *bt,int x1,int y1)
{
if(bt!=NULL)
{
InOrder(k/2,bt->lchild,x1-k,y1+4);
Memory_TreePiont(a,bt,x1,y1);
InOrder(k/2,bt->rchild,x1+k,y1+4);
}
}
/*后序遍历存储二叉树的所有结点*/
void PostOrder(int k,BiTreeNode *bt,int x1,int y1)
{
if(bt!=NULL)
{
PostOrder(k/2,bt->lchild,x1-k,y1+4);
PostOrder(k/2,bt->rchild,x1+k,y1+4);
Memory_TreePiont(a,bt,x1,y1);
}
}

void Memory_xy(BiTree *bt,int x1,int y1)
{
if((*bt)->data!='.')
{
(*bt)->x=x1;
(*bt)->y=y1;
}
}
/*存储所有二叉树的结点在数组a[]中*/
void Memory_TreePiont(TreeArray a[],BiTreeNode *bt,int x1,int y1)
{
if(bt->data!='.')
{
a[i1].color=2;
a[i1].c=bt->data;
a[i1].x=x1;
a[i1++].y=y1;
}
}
/*求树的高*/
int BiTreeDepth(BiTreeNode *bt)
{
int d=0,depthl,depthr;
    if(bt==NULL)return 0;
if(bt->lchild==NULL&&bt->rchild==NULL)
return 1;
depthl=BiTreeDepth(bt->lchild);
depthr=BiTreeDepth(bt->rchild);
d=max(depthl,depthr);
return d+1;
}
int max(int i,int j)
{
return (i>j?i:j);
}
void Find_TreePiont_Delay(TreeArray a[],char fch)
{
int j;
char *a2=(char *)malloc(2*sizeof(char));
a2[0]=fch;
a2[1]='\0';
for(j=0;jlchild==NULL&&bt->rchild==NULL)
{
Draw_TreePiont_One(14,2,0,bt->data,bt->x,bt->y); /*画结点*/
a2[i1++]=bt->data;
a2[i1]='\0';
delay(30000);
delay(30000);
delay(30000);
delay(30000);
delay(30000);
}
Traversr_Leaf(bt->lchild);
Traversr_Leaf(bt->rchild);
}
}

void DeleteTreePiont(BiTree *bt,char ch,char ceng,char flag)
{
if(*bt!=NULL)
{
if((*bt)->data==ch){i3++;}
if((*bt)->data==ch&&(1+(ceng-48)*4)==(*bt)->y&&(flag-48)==i3)
{
Clear_Tree(bt);
}
if((*bt)==NULL){ return;}
DeleteTreePiont(&((*bt)->lchild),ch,ceng,flag);
DeleteTreePiont(&((*bt)->rchild),ch,ceng,flag);
}
}
int Clear_Tree(BiTree *bt)
{

if((*bt)==NULL){ return 0;}
else{
Clear_Tree(&((*bt)->lchild));
Clear_Tree(&((*bt)->rchild));
a2[i1++]=(*bt)->data;
a2[i1]='\0';
No_See_Tree(*bt);
free(*bt);
(*bt)=NULL;

return 1;
   }
}
void No_See_Tree(BiTreeNode *bt)
{
delay(50000);
Draw_TreePiont_One(0,0,0,bt->parent->data,bt->x,bt->y);
delay(50000);
Draw_TreeLine_One(bt,0);
Draw_TreePiont_One(1,2,4,bt->parent->data,bt->parent->x,bt->parent->y);
}
void Insert_TreePiont(BiTree *bt,BiTreeNode *node,char ch,char rl,char ceng,char flag)
{
if((*bt)!=NULL)
{
if((*bt)->data==ch){i3++;}
if((*bt)->data==ch&&(1+(ceng-48)*4)==(*bt)->y&&(flag-48)==i3)
{
if(rl=='l')
{
if((*bt)->y==5&&BiTreeDepth((*bt)->lchild)==4||(*bt)->y==9&&BiTreeDepth((*bt)->lchild)==3||(*bt)->y==13&&BiTreeDepth((*bt)->lchild)==2||(*bt)->y==17&&BiTreeDepth((*bt)->lchild)==1||(*bt)->y==21&&BiTreeDepth((*bt)->lchild)==0)
{
printf_text("high>5 : No insert!",2,2,14);
}
else
{
        node->lchild=(*bt)->lchild;
/*
(*bt)->lchild->parent=node;
*/
(*bt)->lchild=node;
node->parent=(*bt);
node->rchild=NULL;
}
}
if(rl=='r')
{
if((*bt)->y==5&&BiTreeDepth((*bt)->rchild)==4||(*bt)->y==9&&BiTreeDepth((*bt)->rchild)==3||(*bt)->y==13&&BiTreeDepth((*bt)->rchild)==2||(*bt)->y==17&&BiTreeDepth((*bt)->rchild)==1||(*bt)->y==21&&BiTreeDepth((*bt)->rchild)==0)
{
printf_text("high>5 : No insert!",2,2,14);
}
else
{
node->rchild=(*bt)->rchild;
/*
(*bt)->rchild->parent=node;
*/
(*bt)->rchild=node;
node->parent=(*bt);
node->lchild=NULL;
}
}
}
Insert_TreePiont(&((*bt)->lchild),node,ch,rl,ceng,flag);
Insert_TreePiont(&((*bt)->rchild),node,ch,rl,ceng,flag);
}
}
BiTreeNode *Malloc_node(char ch)
{
BiTreeNode *bt=NULL;
bt=(BiTreeNode *)malloc(sizeof(BiTreeNode));
bt->data=ch;
bt->lchild=NULL;
bt->rchild=NULL;
bt->parent=NULL;
bt->x=-1;
bt->y=-1;
return bt;
}
/*数组初始化*/
void InitArray(TreeArray a[])
{
int i;
for(i=0;iparent!=NULL&&bt->data!='.')
{
setcolor(color);
line(X(bt->x),Y(bt->y),X(bt->parent->x),Y(bt->parent->y));
}
Draw_TreeLine_Init(bt->lchild,color);
Draw_TreeLine_Init(bt->rchild,color);
}
}
void Draw_TreePiont_Init(BiTreeNode *bt,char fill,char border,char charcolor)
{
if(bt!=NULL)
{
Draw_TreePiont_One(fill,border,charcolor,bt->data,bt->x,bt->y);
Draw_TreePiont_Init(bt->lchild,fill,border,charcolor);
Draw_TreePiont_Init(bt->rchild,fill,border,charcolor);
}
}
void Draw_TreeLine_One(BiTreeNode *bt,char color)
{
if(bt->parent!=NULL&&bt->data!='.')
{
setcolor(color);
line(X(bt->x),Y(bt->y),X(bt->parent->x),Y(bt->parent->y));
}
}
void Show_Tree(BiTreeNode *bt,char threadcolor,char fill,char border,char charcolor,int i)
{
InitArray(a);
i1=0;
PreOrder(8,bt,17,5,i);                             /*先序遍历二叉树*/
Draw_TreeLine_Init(bt,threadcolor);               /*二叉树树干初始化*/
Draw_TreePiont_Init(bt,fill,border,charcolor);    /*二叉树结点初始化*/
}
/*在图形模式下清屏*/
void clear_pingmu(char color)
{
row(66,8,632,440,color);
}
/*行*/
void row(int starty,int startx,int endx,int l,char color)
{
int i;
for(i=starty;i=5&&p[j+spa]==32){m=4;return m;}
else if(j==4&&p[j-1]==100&&p[j-2]==110&&p[j-3]==105&&p[j-4]==102&&strlen(p)==8&&p[j+spa]==32&&p[j+spa+2]==32){m=5;return m;}
else if(j==6&&p[j-1]==116&&p[j-2]==114&&p[j-3]==101&&p[j-4]==115&&p[j-5]==110&&p[j-6]==105&&strlen(p)>=12&&p[j+spa]==32&&p[j+spa+2]==32&&p[j+spa+4]==32)
{
m=6;return m;
}
}
else break;
}
}
return -1;
}

/*光标*/
void cursor(char color,int x,int y)
{
setcolor(color);
outtextxy(x,y,"_");
}
int space(char *p)
{
int i;
char *a;
a=p;
for(i=0;idata='\0';
(*head)->pre=NULL;
if(bt==NULL) (*head)->next=NULL;
else 
{
pretag=*head;
if(i==1)
PreThreading(bt);
else if(i==2)
InThreading(bt);
else if(i==3)
PosThreading(bt);
pretag->next=NULL;
pretag->next->data='\0';
}
return 1;
}
void PreThreading(BiTreeNode *p)
{
if(p!=NULL)
{
pretag->next=p;
p->pre=pretag;
pretag=p;
PreThreading(p->lchild);
PreThreading(p->rchild);
}
}
void InThreading(BiTreeNode *p)
{
if(p!=NULL)
{
InThreading(p->lchild);
pretag->next=p;
p->pre=pretag;
pretag=p;
InThreading(p->rchild);
}
}
void PosThreading(BiTreeNode *p)
{
if(p!=NULL)
{
PosThreading(p->lchild);
PosThreading(p->rchild);
pretag->next=p;
p->pre=pretag;
pretag=p;
}
}
void printf_thread(BiTreeNode *h)  /*检测是否线索化*/
{
if(h!=NULL)
{
printf("[pre=%c %c next=%c]",h->pre->data,h->data,h->next->data);
printf_thread(h->lchild);
printf_thread(h->rchild);
}
}
