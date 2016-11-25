// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<stdio.h>
typedef struct linkList{
	int data;
	struct linkList *next;
}lNode,*linkList;

//����������ʼ��
linkList create(){
	linkList head = (linkList)malloc(sizeof(lNode));
	head->next = NULL;

	lNode *s; 
	int x = 1;
	while(x){
		s = (linkList)malloc(sizeof(lNode));
		printf("\ninput:");
		scanf("%d",&s->data);
		s->next = head->next;
		head->next = s;
		
		printf("�Ƿ��������");
		scanf("%d",&x);
	}
	return head;
}

//���
int length(linkList head){
	int j = 0;
	lNode *p = head;
	while(p->next != NULL){
		p=p->next;
		j++;
	}
	return j;
}

//�������
linkList deverse(linkList head){
	lNode *s = head->next , *p = head->next->next;
	linkList *b;
	b->next = NULL;
	lNode *r = b;
	while(p != NULL){
		if(p->data < s->data){
			r->next = p;
			r = p;
		}
		p = p->next;
	}
	r->next = s;
	r = s;
	
	p = head->next->next;
	while(p != NULL){
		if(p->data > s->data){
			r->next = p;
			r = p;
		}
		p = p->next;
	}
	r->next = NULL;
	return b;
}

void main(){
	linkList H = create();
	linkList q = deverse(H);
	lNode *t = q;
	while(t != NULL){
		printf("%d ",t->data);
		t = t->next;
	}
	free(q);
}
