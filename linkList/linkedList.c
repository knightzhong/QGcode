#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LNode *p1;
	char blank;	
	printf("请先建立链表。\n");
	printf("请输入你想要存入的值（数字）。注意：每个值用空格隔开，按回车结束存入数字。\n");
/*出错处理：等下写上		
		
		
		
		
		
		
		*********************** */
	
	
	
	*L=(LNode *)malloc(sizeof(LNode));
	p1=*L;
	//scanf("%d",&(*L)->data);
    blank=' ';		
    (*L)->next=NULL;
    
		
	while(blank!='\n')	
	{	(*L)->next=(LNode *)malloc(sizeof(LNode));
		(*L)=(*L)->next;
		
		scanf("%d",&(*L)->data);
		blank=getchar();
		
		
		
		
	
	}	
	(*L)->next=NULL;
	
	(*L)=p1;	
	printf("输入成功！！！！\n");
	return SUCCESS;	
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	
	LNode *p1;
	while(*L!=NULL)
	{	p1=(*L)->next;
		free(*L);
		*L=p1;
	}
	printf("销毁成功哦,愣着干嘛赶紧走人了喂。\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	
	if(p==NULL||q==NULL)
	{	
		printf("传的是假的，骗谁呢？插入节点失败！！\n");
		return ERROR;
	}
	else
	{
	
	printf("开始插入：----------------------------------------------\n ");
	q->next=p->next;
	p->next=q;
	printf("插入成功哦\n");
	
		
	}
	
	
	return SUCCESS;
	
	
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *p1;
/*	if(p->next==NULL);
	{	printf("要删的节点后面都没东西，你要气死我哦。\n");
		return ERROR;
	}  
	*/
	printf("开始删除节点-------------------------------------------------------\n");
	
	*e=p->next->data;
	p1=p->next;
	p->next=p->next->next;
	
	
	printf("删除成功！！！---------------------------------------------------\n");
	free(p1);
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p1=L->next;
	int num=1; 
	if(L==NULL)
	{	
		printf("传进的是空链表玩我呢？？\n");
		return ERROR;
	}
	
	printf("开始查找链表中是否含有e----------------------\n");
	 
	
	
	while(p1!=NULL)
	{
		if(p1->data== e)
		{	printf("查找成功，存在值为%d的点，该点在链表中的第%d位！\n",e,num);
			return SUCCESS;
		}
		
		num++;
		p1=p1->next;
		
	}
	printf("查找完发现没有含%d的这个数的节点！！\n",e);
	return ERROR;
	
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList pt,p2,p3;
	if(*L==NULL){
		printf("传来的是空链表哦，请先创建链表。\n");
		return ERROR;
	}
	
	p2=(*L)->next;           //开头的处理 
	(*L)->next=NULL;
	p3=p2->next;
	p2->next=NULL;
	
	
	while(p3->next!=NULL)     //迭代处理之后的 
	{
		pt=p3->next;
		p3->next=p2;
		p2=p3;
		p3=pt;
		
		
	}
	
	p3->next=p2;
	
	
	(*L)->next= p3;       //头指针的处理 
	return SUCCESS;
		
		
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p2=L->next,p1=L->next;
	int i=0;
	
	if(L==NULL){
		printf("传入的是空链表，创建链表时出错了，请检查。\n");
		return ERROR;
	}
	
	
	
	for(i=0;i<100;i++)    //判断是否成环 
	{	p2=p2->next->next;
		p1=p1->next;	
		if(p1->data==p2->data)
		{
			printf("此链表是成环链表哦！！！\n");
			return SUCCESS;
		}
		
		if(p2==NULL||p2->next==NULL||p2->next->next==NULL)
		i=100;
	
	}
	
	
	printf("此链表_没_成环哦\n");
	return ERROR;
}
/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	int i=2;
	LinkedList p1=(*L)->next,p2=(*L)->next->next,p3;
	
	
	
	while(p2!=NULL){
		if(i%2==0){
			if(i==2){
				p1->next=p2->next;
				p2->next=p1;
				(*L)->next=p2;
				
			}
			else{
				p1->next=p2->next;
				p2->next=p1;
				p3->next=p2;
				
			}
				                 //节点交换完毕
			
			p3=p2;			//p1始终在p2的前面，利用循环一直交换位置。 
			p2=p1;
			p1=p3; 
			
			
			        //记录当前p1的位置，之后方便交换。	
		}
		p3=p1;
		p1=p1->next;
		p2=p2->next;
		
		i++;
							
	} 
	
	return *L;
	
}
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p1=(*L)->next,p2=(*L)->next;
	
	int i=1;
	for(;p1->next!=NULL;i++,p1=p1->next);
		
	if(i%2==0){
		printf("链表实际长度为偶数，无法找到中点。\n");
		return NULL;
	
	}	
	p1=p2;	//对p1重置处理； 
	
	
	while(p2->next!=NULL){
		
		p2=p2->next->next;
		p1=p1->next;
		
	}
	
	
	return p1; 
	
		
}

