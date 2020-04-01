#include<stdio.h>
#include "../head/linkedList.h"
#include<stdlib.h>
#include "../linklist/linkedList.c"
Status Print(int choice);
LinkedList L; 
int count;

void main(){
	int choice=0;
	
	InitList(&L);
	LinkedList p1=L->next,p2;
	
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






Status Print(int choice)
{ int judge=0,cLocation,i=1,e;
  LinkedList p1=L,p2,p3=L->next;
  int choice1,choice2;
  system("cls");
  switch(choice)
  { case 0:
		printf("**********************************************************************\n");
		printf("*1--销毁链表  2--删除节点  3--找到中点  4--插入节点  5--寻找对应节点 *\n");
		printf("***********************************************************************************\n");
		printf("*6--判断链表是否成环  7--反转链表   8--奇偶对换节点位置  9--还未开发  10--退出程序*\n");
		printf("***********************************************************************************\n");
		printf("Please choose from them:(1 to 9) ");
			scanf("%d",&choice1);
		
			while(choice>10||choice<0)
			{
				printf("输入了错误的数字哦，好好看下,重新选择：\n");
				scanf("%d",&choice1); 
				
			} 
			Print(choice1);
			break;

    case 1:
		printf("***************************************************************\n");
		printf("*----------------------你选择了销毁链表-----------------------*\n");
		printf("***************************************************************\n");
		DestroyList(&L);
		
		break;
    case 2:
		printf("**************************************************************\n");
		printf("*----------------------你选择了删除节点----------------------*\n");
		printf("**************************************************************\n");
		printf("一共有%d个数，请问你要删除第几个？\n",count);
		scanf("%d",&judge);
		
		while(judge<1||judge>count)				//出错处理。 
		{
			printf("没有该点的位置，请重新输入：");
			scanf("%d",&judge);
		}
		
		if(judge>i)
		for(i=1;i<judge;i++){
			p1=p1->next;
		}
		
		
		
		DeleteList(p1, &e);
		printf("你要删除的节点里面的数据是：%d\n",e);
		printf("现在链表的值为："); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
    case 3:
		printf("***************************************************************\n");
		printf("*----------------------你选择了找到中点-----------------------*\n");
		printf("***************************************************************\n");
		p2=FindMidNode(&L);
		printf("该点的内容是-%d-\n",p2->data);
		break;
	
    case 4:
		printf("***************************************************************\n");
		printf("*----------------------你选择了插入节点-----------------------*\n");
		printf("***************************************************************\n");
		
		printf("请说出想在第几个位置插入？\n");
		scanf("%d",&cLocation);
		if(cLocation>i)
		for(i=1;i<cLocation;i++){
			p1=p1->next;
		}
		
		printf("请填入你想插入的数：\n");
		p2=(LinkedList)malloc(sizeof(LNode));
		scanf("%d",&p2->data); 
		
		InsertList(p1,p2);
		
		printf("现在链表的值为："); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
    case 5:
		printf("***************************************************************\n");
		printf("*--------------------你选择了寻找对应节点---------------------*\n");
		printf("***************************************************************\n");
		printf("-----请说出你想查找的数字-----\n");
		scanf("%d",&e);
		
		SearchList(L, e);
		break;
	
	case 6:
		printf("***************************************************************\n");
		printf("*-----------------你选择了判断链表是否成环--------------------*\n");
		printf("***************************************************************\n");
		IsLoopList(L);
		
		break;
	
	case 7:
		printf("***************************************************************\n");
		printf("*----------------------你选择了反转链表-----------------------*\n");
		printf("***************************************************************\n");
		ReverseList(&L);
		
		p3=L->next;
		printf("现在链表的值为："); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
	
	case 8:
		printf("***************************************************************\n");
		printf("*------------------你选择了奇偶对换节点位置-------------------*\n");
		printf("***************************************************************\n");
		ReverseEvenList(&L);
		
		p3=L->next;
		printf("现在链表的值为："); 	
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		break;
	
	case 9:
		printf("***************************************************************\n");
		printf("*----------------------你选择了还未开发-----------------------*\n");
		printf("***************************************************************\n");
		
		printf("现在链表的值为："); 
		while(p3!=NULL)
		{
			printf("%d  ",p3->data);
			p3=p3->next;
		}
		printf("\n");
		
		break;
	
	case 10:
		exit(EXIT_SUCCESS);
	
	 
	
	


  }
}
