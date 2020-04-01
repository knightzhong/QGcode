#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLNode *p1;
	char blank;	
	printf("请输入你想要存入的值（数字）。注意：每个值用空格隔开，按回车结束存入数字。\n");
/*出错处理：等下写上		
		
		
		
		
		
		
		*********************** */
	
	
	
	*L=(DuLNode *)malloc(sizeof(DuLNode));
	p1=*L;
	//scanf("%d",&(*L)->data);
    blank=' ';		
    (*L)->next=NULL;
    (*L)->prior=NULL;
    
		
	while(blank!='\n')	
	{	(*L)->next=(DuLNode *)malloc(sizeof(DuLNode));
		(*L)->next->prior=(*L);
		(*L)=(*L)->next;

		scanf("%d",&(*L)->data);
		blank=getchar();
		
		
		
		
	
	}	
	(*L)->next=NULL;
	
	(*L)=p1;	
	
	return SUCCESS;	
	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p1;
	while(*L!=NULL)
	{	p1=(*L)->next;
		free(*L);
		*L=p1;
	}
	printf("销毁成功哦,愣着干嘛赶紧走人了喂。\n");
}


/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
		
	if(p==NULL||q==NULL)
	{	
		printf("传的是假的，骗谁呢？插入指针失败！！\n");
		return ERROR;
	}
	else
	{
	
	printf("开始插入：----------------------------------------------\n ");
	q->prior=p->prior;			//前指针 
	p->prior=q;
	
	q->next=p;						//后指针 
	q->prior->next=q;

	printf("插入成功哦");
	
		
	}
	
	
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL||q==NULL)
	{	
		printf("传的是假的，骗谁呢？插入指针失败！！\n");
		return ERROR;
	}
	else
	{
	
	printf("开始插入：----------------------------------------------\n ");
	q->next=p->next;
	p->next=q;
	
	q->prior=p;
	q->next->prior=q; 
	printf("插入成功哦");
	
		
	}
	
	
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLNode *p1;
/*	if(p->next==NULL);
	{	printf("要删的节点后面都没东西，你要气死我哦。\n");
		return ERROR;
	}  */
	
	printf("开始删除节点-------------------------------------------------------\n");
	
	*e=p->next->data;
	p1=p->next;
	p->next=p->next->next;
	p->next->prior=p;
	
	
	printf("删除成功！！！---------------------------------------------------\n");
	free(p1);
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
}
