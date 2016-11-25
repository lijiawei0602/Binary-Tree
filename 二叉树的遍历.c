#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define MAXSIZE 100
//二叉树结构体 
typedef struct Node{
	char data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree; 

//栈的结构体
typedef struct{
	BiTree data[MAXSIZE];
	int top;
}SeqStack; 
 
// 队列的结构体
typedef struct{
	BiTree data[MAXSIZE];	//队列的存储区 
	int front,rear;		//队头队尾指针 
}cseQueue;				//循环队 
 
//栈的初始化
SeqStack *init(){
	SeqStack *s;
	s = (SeqStack *)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
} 
 
//获取栈顶元素
BiTree getTop(SeqStack *s)
{
	if(s->top ==-1)
		return;
	else{
		return s->data[s->top];
	}
 } 
 
 //入栈
void push(SeqStack *s , BiTree ch)
 {
 	if(s->top != MAXSIZE-1)
 	{
 		s->top++;
 		s->data[s->top] = ch;
	 }
  } 
 
 //出栈 
void pop(SeqStack *s, BiTree *ch)
 {
	if(s->top != -1)
	{
		*ch = s->data[s->top];
		s->top--;	
	}	
 }
 
 //队列初始化
 cseQueue *initQueue(){
 	cseQueue *q;
	q = (cseQueue *)malloc(sizeof(cseQueue));
 	q->front = q->rear = 0;
 	return q;
 }
  
 //入队
 void inSeQueue(cseQueue *q,BiTree x){
 	if((q->rear+1)%MAXSIZE == q->front){
		printf("\n队满");
	 }
	 else{
	 	q->data[q->rear] =x;
	 	++q->rear;
	 }
 } 
 
 //出队
BiTree *outSeQueue(cseQueue *q,BiTree *x){
 	if(q->front == q->rear){
 		printf("\n队空");
 		return;
	 }
	 else{
	 	*x = q->data[q->front];
	 	++q->front;
	 	return x;
	 }
 } 
  
//用扩展线序方法创建二叉树 
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

//桉树状打印二叉树
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
 
 //先序递归输出
 void preOrder(BiTree root){
 	if(root != NULL)
 	{
 		printf("%c ",root->data);
 		preOrder(root->lChild);
		preOrder(root->rChild);	
	}	
 } 
 
 //中序递归输出
 void InOrder(BiTree root)
 {
 	if(root !=NULL)
 	{
 		InOrder(root->lChild);
 		printf("%c ",root->data);
 		InOrder(root->rChild);
	 }
  } 

//先序非递归遍历输出
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
  
//中序非递归遍历输出
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
  //后序非递归输出
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

 //结点以及结点所在层次
 void printLevel(BiTree root , int h){
 	if(root){
	 
		 printf("(%c,%d)",root->data,h);
	 	printLevel(root->lChild,h+1);
	 	printLevel(root->rChild,h+1);
	 }
 } 
 
 //交换左右子树
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
 

 //	输出路径
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

//按层遍历
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

//输出指定层的叶子结点个数
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

//先序+中序 结点序列恢复
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

//	后序+中序 结点序列恢复
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
//寻找共同祖先
void prefix(BiTree root){
	char c1,c2;
	scanf("%c %c",&c1,&c2);
	
} 

void main()
{	
//	char arr[50];
//	BiTree root;
//	root = create();
	//交换左右子树
//	exchange(root);
//	preOrder1(root);
//	printf("\n");
//	inOrder1(root);
//	printf("\n");
//	postOrder(root);
//	桉树状输出 
//	printTree(root , 1); 
//	先序遍历输出 
//	preOrder(root); 
//	中序遍历输出 
//	inOrder(root);
//后序非递归遍历输出
//	postOrder(root); 
//先序非递归遍历输出
//	preOrder1(root); 
//	printf("\n"); 
//中序非递归遍历输出
//	inOrder1(root); 
//结点以及结点层次
//	printLevel(root,1); 
//输出路径
//	printRoute(root,arr,0); 
//按层遍历
//	levelOrder(root); 
//输出指定层的叶子结点个数
//	int x;
//	scanf("%d",&x);
//	numOfLeave1(root,1,x); 
//	printf("%d",count);
//先序+中序 结点序列恢复
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
//	后序+中序 结点序列恢复
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
