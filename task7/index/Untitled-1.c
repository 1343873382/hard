#include<ctype.h>
#include<malloc.h> /* malloc()等 */
#include<stdio.h> 
#include<stdlib.h>
#include<process.h> /* exit() */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
typedef int ElemType;
#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LIST_INCREMENT 2 /* 线性表存储空间的分配增量 */
typedef struct/* 线性表的动态分配顺序存储结构 */
{
   ElemType *elem; /* 存储空间基址 */
   int length; /* 当前长度 */
   int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
}SqList;

/* 顺序表示的线性表的基本操作,包括算法2.3,2.4,2.5*/
void InitList(SqList *L) /* 算法2.3 */
{ /* 操作结果：构造一个空的顺序线性表L */
   (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
     exit(OVERFLOW); /* 存储分配失败 */
   (*L).length=0; /* 空表长度为0 */
   (*L).listsize=LIST_INIT_SIZE; /* 初始存储容量 */
}

void DestroyList(SqList *L)
{ /* 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L */
   free((*L).elem);
   (*L).elem=NULL;
   (*L).length=0;
   (*L).listsize=0;
}

/* 请将下面函数补充完整 */
Status ListInsert(SqList *L,int i,ElemType e) /* 算法2.4 */
{ /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1 */
   /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
   int j; 	
	
	for(j=0;j<(*L).length-i+1;j++){
            *((*L).elem+i+j)=*((*L).elem+i+j-1) ;
	}
	*((*L).elem+i-1)=e;
	return OK;

}


/* 请将下面函数补充完整 */
Status ListDelete(SqList *L,int i,ElemType *e) /* 算法2.5 */
{ /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
   /* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
     int j;
   
     e=((*L).elem+i-1);
	for(j=0;j<(*L).length-i+1;j++){
            *((*L).elem+i+j-1)=*((*L).elem+i+j);
	}
   return OK;

}


void ListTraverse(SqList L)
{ /* 初始条件：顺序线性表L已存在 */
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
     printf("%3d",*p++);
   printf("\n");
 }

void main()
{
	SqList L;
	ElemType e;
	Status i;
	int j;
	InitList(&L);
	for(j=1;j<=5;j++)
		i=ListInsert(&L,1,j);
	printf("依次输出L的元素：");
	ListTraverse(L);
	i=ListDelete(&L,3,&e); /* 删除第j个数据 */
	if(i==ERROR)
		printf("删除元素失败\n");
	else
		printf("删除元素成功，其值为：%d\n",e);
	printf("删除元素后L的元素：");
	ListTraverse(L);
	DestroyList(&L);
 }
