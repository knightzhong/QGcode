#include<stdio.h>
#include "../head/dulinkedList.h"
#include<stdlib.h>
#include "../dulinklist/dulinkedList.c"
void Print(int choice);
DuLinkedList L; 
int count;

void main(){
	int choice=0;
	
	InitList_DuL(&L);
	DuLinkedList p1=L->next,p2;
	
	while(p1!=NULL)
	{	count++;
		p1=p1->next;
	}
	
	Print(0);

	while(L!=NULL)
	{	p2=L->next;
		free(L);
		L=p2;
	}

		
	
}






void Print(int choice)
{ int judge=0,cLocation,i=1,e;
  DuLinkedList p1=L,p2,p3=L->next;
  int choice1,choice2;
  system("cls");
  switch(choice)
  { case 0:
		printf("************************************************************************\n");
		printf("*1--��������  2--ɾ���ڵ�  3--����ڵ�(ǰ)  4--����ڵ㣨�� 5--δ����*\n");
		printf("************************************************************************\n");
	
		printf("Please choose from them:(1 to 5) ");
			scanf("%d",&choice1);
		
			while(choice>6||choice<0)
			{
				printf("�����˴��������Ŷ���úÿ���,����ѡ��\n");
				scanf("%d",&choice1); 
				
			} 
			Print(choice1);
			break;

    case 1:
		printf("***************************************************************\n");
		printf("*----------------------��ѡ������������-----------------------*\n");
		printf("***************************************************************\n");
		DestroyList_DuL(&L);
		
		break;
    case 2:
		printf("**************************************************************\n");
		printf("*----------------------��ѡ����ɾ���ڵ�----------------------*\n");
		printf("**************************************************************\n");
		printf("һ����%d������������Ҫɾ���ڼ�����\n",count);
		scanf("%d",&judge);
		
		while(judge<1||judge>count)				//������ 
		{
			printf("û�иõ��λ�ã����������룺");
			scanf("%d",&judge);
		}
		
		if(judge>i)
		for(i=1;i<judge;i++){
			p1=p1->next;
		}
		
		
		
		DeleteList_DuL(p1, &e);
		printf("��Ҫɾ���Ľڵ�����������ǣ�%d\n",e);
		printf("���������ֵΪ��"); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
    case 3:
		printf("****************************************************************\n");
		printf("*--------------------��ѡ���˲���ڵ㣨ǰ��--------------------*\n");
		printf("****************************************************************\n");
		printf("��˵�����ڵڼ���λ�ò��룿\n");
		scanf("%d",&cLocation);
		if(cLocation>i)
		for(i=0;i<cLocation;i++){
			p1=p1->next;
		}
		
		printf("������������������\n");
		p2=(DuLinkedList)malloc(sizeof(DuLNode));
		scanf("%d",&p2->data); 
		
		InsertBeforeList_DuL(p1,p2);
		
		printf("���������ֵΪ��"); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
	
    case 4:
		printf("*****************************************************************\n");
		printf("*--------------------��ѡ���˲���ڵ㣨��---------------------*\n");
		printf("*****************************************************************\n");
		
		printf("��˵�����ڵڼ���λ�ò��룿\n");
		scanf("%d",&cLocation);
		if(cLocation>i)
		for(i=1;i<cLocation;i++){
			p1=p1->next;
		}
		
		printf("������������������\n");
		p2=(DuLinkedList)malloc(sizeof(DuLNode));
		scanf("%d",&p2->data); 
		
		InsertAfterList_DuL(p1,p2);
		
		printf("���������ֵΪ��"); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
    case 5:
		printf("***************************************************************\n");
		printf("*--------------------��ѡ����δ����---------------------*\n");
		printf("***************************************************************\n");
	

	case 6:
		exit(EXIT_SUCCESS);
	
	 
	
	


  }
}
