#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define MAXSIZE 100
//�������ṹ�� 
typedef struct Node{
	char data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree; 

//ջ�Ľṹ��
typedef struct{
	BiTree data[MAXSIZE];
	int top;
}SeqStack; 
 
// ���еĽṹ��
typedef struct{
	BiTree data[MAXSIZE];	//���еĴ洢�� 
	int front,rear;		//��ͷ��βָ�� 
}cseQueue;				//ѭ���� 
 
//ջ�ĳ�ʼ��
SeqStack *init(){
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
} 
 
//��ȡջ��Ԫ��
BiTree getTop(SeqStack *s)
{
	if(s->top ==-1)
		return;
	else{
		return s->data[s->top];
	}
 } 
 
 //��ջ
void push(SeqStack *s , BiTree ch)
 {
 	if(s->top != MAXSIZE-1)
 	{
 		s->top++;
 		s->data[s->top] = ch;
	 }
  } 
 
 //��ջ 
void pop(SeqStack *s, BiTree *ch)
 {
	if(s->top != -1)
	{
		*ch = s->data[s->top];
		s->top--;	
	}	
 }
 
 //���г�ʼ��
 cseQueue *initQueue(){
 	cseQueue *q;
	q = (cseQueue *)malloc(sizeof(cseQueue));
 	q->front = q->rear = 0;
 	return q;
 }
  
 //���
 void inSeQueue(cseQueue *q,BiTree x){
 	if((q->rear+1)%MAXSIZE == q->front){
		printf("\n����");
	 }
	 else{
	 	q->data[q->rear] =x;
	 	++q->rear;
	 }
 } 
 
 //����
BiTree *outSeQueue(cseQueue *q,BiTree *x){
 	if(q->front == q->rear){
 		printf("\n�ӿ�");
 		return;
	 }
	 else{
	 	*x = q->data[q->front];
	 	++q->front;
	 	return x;
	 }
 } 
  
//����չ���򷽷����������� 
BiTree create(){
	BiTree s;
	char ch;
	ch = getchar();
	if(ch == '#')
	{
		return NULL;		 
	}
	else{
		s = malloc(sizeof(BiTNode));
		s->data = ch;
		s->lChild = create();
		s->rChild = create();
		return s;
	}
}

//����״��ӡ������
void printTree(BiTree root , int h)
{	int i;
	if(root == NULL)
		return;
	printTree(root->rChild , h+1);
	for(i = 0;i<h; i++)
	{
		printf(" ");
	}
	printf("%c\n",root->data);
	printTree(root->lChild , h+1);
 } 
 
 //����ݹ����
 void preOrder(BiTree root){
 	if(root != NULL)
 	{
 		printf("%c ",root->data);
 		preOrder(root->lChild);
		preOrder(root->rChild);	
	}	
 } 
 
 //����ݹ����
 void InOrder(BiTree root)
 {
 	if(root !=NULL)
 	{
 		InOrder(root->lChild);
 		printf("%c ",root->data);
 		InOrder(root->rChild);
	 }
  } 

//����ǵݹ�������
void preOrder1(BiTree root){
	SeqStack *s;
	BiTree p,q;
	s = init();
	p = root;
	
	while(p!=NULL || s->top != -1)
	{	
		while(p)
		{	printf("%c",p->data);
			push(s,p);
			p = p->lChild;
		}
		if(s->top != -1){
			pop(s,&p);
//			printf("%d",s->top); 
			p = p->rChild;
		}
	}
} 
  
//����ǵݹ�������
void inOrder1(BiTree root){
	SeqStack *s;
	BiTree p,q;
	s = init();
	p = root;

	while(p!=NULL || s->top != -1)
	{	
		while(p)
		{
			push(s,p);
			p = p->lChild;
		}
		if(s->top != -1){
			pop(s,&p);
			printf("%c",p->data);
			p = p->rChild;
		}
	}
} 
  //����ǵݹ����
  void postOrder(BiTree root)
  {
	SeqStack *s;
	BiTree p,q;
	s = init();
	p = root;
	q = NULL;
	
	while(p!=NULL || s->top != -1)
	{	
		while(p)
		{	
			push(s,p);
			p = p->lChild;
		}
		if(s->top != -1){
			p = getTop(s);
			if(p->rChild == NULL || p->rChild == q)
			{
				pop(s,&p);
				printf("%c",p->data);
				q = p;
				p = NULL;
			}
			else
				p = p->rChild;
		}
	}
} 

 //����Լ�������ڲ��
 void printLevel(BiTree root , int h){
 	if(root){
	 
		 printf("(%c,%d)",root->data,h);
	 	printLevel(root->lChild,h+1);
	 	printLevel(root->rChild,h+1);
	 }
 } 
 
 //������������
 void exchange(BiTree root){
 	BiTree c;
	 if(root){
	 	c = root->lChild;
	 	root->lChild = root->rChild;
	 	root->rChild = c;
	 	exchange(root->lChild);
		exchange(root->rChild);
	 }
	  
 } 
 

 //	���·��
void printRoute(BiTree root,char arr[] ,int m)
{	int j;
	if(root)
	{
		arr[m] = root->data;
		if(root->lChild == NULL && root->rChild == NULL)
		{
			printf("%c:",root->data);
			for(j=0;j<m;j++)
			{
				printf("%c",arr[j]);
			}
			printf("\n");
		}
		printRoute(root->lChild,arr,m+1);
		printRoute(root->rChild,arr,m+1);
	}
 } 

//�������
void levelOrder(BiTree root){
	cseQueue *q;
	BiTree p;
	q = initQueue();
	inSeQueue(q,root);
	while(!(q->front == q->rear)){
		outSeQueue(q,&p);
		printf("%c",p->data);
		
		if(p->lChild != NULL){
			inSeQueue(q,p->lChild);
		}		
		if(p->rChild != NULL){
			inSeQueue(q,p->rChild);
		}
	}
} 

//���ָ�����Ҷ�ӽ�����
 int count = 0;
 
 void numOfLeave1(BiTree root,int height,int x){
 	if(root){
		 if(x == height && root->lChild ==NULL && root->rChild ==NULL){
	 		++count;
		 }
		 numOfLeave1(root->lChild,height+1,x);
		 numOfLeave1(root->rChild,height+1,x);
	}
} 

//����+���� ������лָ�
BiTree createByPI(char *pre,char *in,int n){
	BiTree s;
	int pos=0;
	if(n<=0)
		return NULL;
	s = malloc(sizeof(BiTNode));
	s->data = *pre;

	while(pos<n){
		if(*pre == in[pos])
			break;
		pos++;
	}
	s->lChild = createByPI(pre+1,in,pos);
	s->rChild = createByPI(pre+pos+1,in+pos+1,n-pos-1);
	return s;
} 

//	����+���� ������лָ�
BiTree createByIP(char *in,char *post,int n){
//	BiTree s;
//	int pos = 0;
//	if(n<=0)
//		return NULL;
//	s = malloc(sizeof(BiTNode));
//	s->data = post[n-1];
//	s->lChild = NULL;
//	s->rChild = NULL;
//	
//	while(pos<n){
//		if(post[n-1] == in[pos]);
//			break;
//		pos++;
//	}
//	s->lChild = createByIP(in,post,pos);
//	s->rChild = createByIP(in+pos+1,post+pos,n-pos-1);
//	return s;

	BiTree s;
	int pos = 0;
	if(n <= 0)
		return NULL;
	s = (BiTree)malloc(sizeof(BiTNode));
	s->data = post[n-1];

	while(pos<n){
		if(post[n-1] == in[pos])
			break;
		pos++;
	}
	s->lChild = createByIP(in,post,pos);
	s->rChild = createByIP(in+pos+1,post+pos,n-pos-1);
	return s;

}
//Ѱ�ҹ�ͬ����
void prefix(BiTree root){
	char c1,c2;
	scanf("%c %c",&c1,&c2);
	
} 

void main()
{	
//	char arr[50];
//	BiTree root;
//	root = create();
	//������������
//	exchange(root);
//	preOrder1(root);
//	printf("\n");
//	inOrder1(root);
//	printf("\n");
//	postOrder(root);
//	����״��� 
//	printTree(root , 1); 
//	���������� 
//	preOrder(root); 
//	���������� 
//	inOrder(root);
//����ǵݹ�������
//	postOrder(root); 
//����ǵݹ�������
//	preOrder1(root); 
//	printf("\n"); 
//����ǵݹ�������
//	inOrder1(root); 
//����Լ������
//	printLevel(root,1); 
//���·��
//	printRoute(root,arr,0); 
//�������
//	levelOrder(root); 
//���ָ�����Ҷ�ӽ�����
//	int x;
//	scanf("%d",&x);
//	numOfLeave1(root,1,x); 
//	printf("%d",count);
//����+���� ������лָ�
//	BiTree root;
//	int z;
//	char p[50],q[50];
//	scanf("%s",p);
//	scanf("%s",q);
//	
//	char *pre = p;
//	char *in = q;
//	z=strlen(p);
//	
//	root = createByPI(pre,in,z);
//	postOrder(root);
//	����+���� ������лָ�
//	BiTree root;
//	int z;
//	char p[50],q[50];
//	scanf("%s",p);
//	scanf("%s",q);
//	
//	char *in = p;
//	char *post = q;
//	z= strlen(p);
//	root = createByIP(in,post,z);
//	preOrder1(root);
 }
