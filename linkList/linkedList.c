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
	printf("���Ƚ�������\n");
	printf("����������Ҫ�����ֵ�����֣���ע�⣺ÿ��ֵ�ÿո���������س������������֡�\n");
/*����������д��		
		
		
		
		
		
		
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
	printf("����ɹ���������\n");
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
	printf("���ٳɹ�Ŷ,��Ÿ���Ͻ�������ι��\n");
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
		printf("�����Ǽٵģ�ƭ˭�أ�����ڵ�ʧ�ܣ���\n");
		return ERROR;
	}
	else
	{
	
	printf("��ʼ���룺----------------------------------------------\n ");
	q->next=p->next;
	p->next=q;
	printf("����ɹ�Ŷ\n");
	
		
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
	{	printf("Ҫɾ�Ľڵ���涼û��������Ҫ������Ŷ��\n");
		return ERROR;
	}  
	*/
	printf("��ʼɾ���ڵ�-------------------------------------------------------\n");
	
	*e=p->next->data;
	p1=p->next;
	p->next=p->next->next;
	
	
	printf("ɾ���ɹ�������---------------------------------------------------\n");
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
		printf("�������ǿ����������أ���\n");
		return ERROR;
	}
	
	printf("��ʼ�����������Ƿ���e----------------------\n");
	 
	
	
	while(p1!=NULL)
	{
		if(p1->data== e)
		{	printf("���ҳɹ�������ֵΪ%d�ĵ㣬�õ��������еĵ�%dλ��\n",e,num);
			return SUCCESS;
		}
		
		num++;
		p1=p1->next;
		
	}
	printf("�����귢��û�к�%d��������Ľڵ㣡��\n",e);
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
		printf("�������ǿ�����Ŷ�����ȴ�������\n");
		return ERROR;
	}
	
	p2=(*L)->next;           //��ͷ�Ĵ��� 
	(*L)->next=NULL;
	p3=p2->next;
	p2->next=NULL;
	
	
	while(p3->next!=NULL)     //��������֮��� 
	{
		pt=p3->next;
		p3->next=p2;
		p2=p3;
		p3=pt;
		
		
	}
	
	p3->next=p2;
	
	
	(*L)->next= p3;       //ͷָ��Ĵ��� 
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
		printf("������ǿ�������������ʱ�����ˣ����顣\n");
		return ERROR;
	}
	
	
	
	for(i=0;i<100;i++)    //�ж��Ƿ�ɻ� 
	{	p2=p2->next->next;
		p1=p1->next;	
		if(p1->data==p2->data)
		{
			printf("�������ǳɻ�����Ŷ������\n");
			return SUCCESS;
		}
		
		if(p2==NULL||p2->next==NULL||p2->next->next==NULL)
		i=100;
	
	}
	
	
	printf("������_û_�ɻ�Ŷ\n");
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
				                 //�ڵ㽻�����
			
			p3=p2;			//p1ʼ����p2��ǰ�棬����ѭ��һֱ����λ�á� 
			p2=p1;
			p1=p3; 
			
			
			        //��¼��ǰp1��λ�ã�֮�󷽱㽻����	
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
		printf("����ʵ�ʳ���Ϊż�����޷��ҵ��е㡣\n");
		return NULL;
	
	}	
	p1=p2;	//��p1���ô��� 
	
	
	while(p2->next!=NULL){
		
		p2=p2->next->next;
		p1=p1->next;
		
	}
	
	
	return p1; 
	
		
}

