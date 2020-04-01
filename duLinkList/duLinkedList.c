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
	printf("����������Ҫ�����ֵ�����֣���ע�⣺ÿ��ֵ�ÿո���������س������������֡�\n");
/*����������д��		
		
		
		
		
		
		
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
	printf("���ٳɹ�Ŷ,��Ÿ���Ͻ�������ι��\n");
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
		printf("�����Ǽٵģ�ƭ˭�أ�����ָ��ʧ�ܣ���\n");
		return ERROR;
	}
	else
	{
	
	printf("��ʼ���룺----------------------------------------------\n ");
	q->prior=p->prior;			//ǰָ�� 
	p->prior=q;
	
	q->next=p;						//��ָ�� 
	q->prior->next=q;

	printf("����ɹ�Ŷ");
	
		
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
		printf("�����Ǽٵģ�ƭ˭�أ�����ָ��ʧ�ܣ���\n");
		return ERROR;
	}
	else
	{
	
	printf("��ʼ���룺----------------------------------------------\n ");
	q->next=p->next;
	p->next=q;
	
	q->prior=p;
	q->next->prior=q; 
	printf("����ɹ�Ŷ");
	
		
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
	{	printf("Ҫɾ�Ľڵ���涼û��������Ҫ������Ŷ��\n");
		return ERROR;
	}  */
	
	printf("��ʼɾ���ڵ�-------------------------------------------------------\n");
	
	*e=p->next->data;
	p1=p->next;
	p->next=p->next->next;
	p->next->prior=p;
	
	
	printf("ɾ���ɹ�������---------------------------------------------------\n");
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
