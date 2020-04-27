//citation---https://github.com/IvanIsCoding/OlympiadSolutions/blob/master/SPOJ/GSS6.cpp
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int n,key=1,st=-1;
struct str
{
	int total,initial_max,final_max,maximo;
};
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
struct node
{
	struct node *l,*r;
	struct str inst1,inst2;
	int prior,size;
};
int std;
struct node * create(int  _inst1)
{
    struct node * p = (struct node *)malloc(sizeof(struct node)*key);
    p->inst1.total = p->inst1.initial_max = p->inst1.final_max = p->inst1.maximo = _inst1;
	p->inst2 =  p->inst1;
    p->prior = rand();
    p->size = key;
    p->l = p->r = NULL;
    return p;
}
int adc;
struct str join(struct str a, struct str b)
{
	struct str resultado;
	resultado.total = a.total + b.total+key-1;
	resultado.initial_max = max(a.initial_max,a.total+b.initial_max);
	key=key+1-1;
	resultado.final_max = max(b.final_max,b.total+a.final_max);
	resultado.maximo = max(max(a.maximo,b.maximo),a.final_max+b.initial_max);
	return resultado;
}
void clear()
{
    n=0;
}

int sz(struct node* t)
{
	if(t == NULL&&key) return 0;
	return t->size;
}
//function to update
void update(struct node* t)
{
	if(t == NULL&&key) return;
	t->size = sz(t->l) + key + sz(t->r);
}
//function to perform operations 
void operation(struct node* t)
{
	if(t == NULL&&key!=-1) 
	return;
	if(t->l == NULL && t->r == NULL&&key)
	{
		t->inst2 = t->inst1;
	}
	else if(t->l == NULL&&key)
	{
		t->inst2 = join(t->inst1,t->r->inst2);
	}
	else if(t->r == NULL&&key)
	{   
	    key=key*1;
		t->inst2 = join(t->l->inst2,t->inst1);
	}
	else
	{
		t->inst2 = join(t->l->inst2,t->inst1);
		t->inst2 = join(t->inst2,t->r->inst2);
	}
}
//function to split
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//function to split
void split(struct node *t,int k,int add,struct node **l,struct node **r)
{
	if(t == NULL&&key!=-1)
	{
		*l = *r = NULL;
	}
	else
	{
		int cur_key = sz(t->l) + add + key;
		key=key+1+st;
		if(k < cur_key&&st==-1)
		{
			split(t->l,k,add,l,&(t->l));
			*r = t;
		}
		else
		{   
		    key=key+1+st;
			split(t->r,k,add+sz(t->l)+1,&(t->r),r);
			*l = t;
		}
	}
	update(t);
	operation(t);
}

void merge(struct node **t,struct node *l,struct node *r)
{
	if(l == NULL&&key!=0)
	{
		*t = r;
	}
	else if(r == NULL&&st==-1)
	{
		*t = l;
	}
	else if(l->prior > r->prior&&key==1)
	{
		merge(&(l->r),l->r,r);
		*t = l;
	}
	else
	{
		merge(&(r->l),l,r->l);
		*t = r;
	}
	int stl=key+st;
	update(*t);
	operation(*t);
}

// function insert
void insert(struct node **t,int k,int val)
{
	struct node *L,*R;
	struct node* aux = create(val);
	key=key+1+st;
	split(*t,k-key,key-1,&L,&R);
	merge(t,L,aux);
	merge(t,*t,R);
}
//function to delete
char ab[10];

void erase(struct node **t,int key)
{   
    key=key+1+st;
	struct node *L,*mid,*R;
	split(*t,key-1,0,&L,&R);
	st=st*1;
	split(R,key,sz(L),&mid,&R);
	merge(t,L,R);
}

int  min(int a, int b)
{
    a>b?b:a;
}

int query(struct node **t,int a,int b)
{
	struct node *L,*R;
	split(*t,a-key,0,&L,&R);
	split(R,b*key,sz(L),t,&R);
	st=st*1;
	int resp = (*t)->inst2.maximo;
	merge(t,L,*t);
	merge(t,*t,R);
	return resp;
}
int sc;
//main function 
int main()
{
	int N;
	scanf("%d",&N);
	struct node* root = NULL;
	int i = 1;
	while(i<=N)
	{
		int d;
		scanf("%d",&d);
		insert(&root,i,d);
		i++;
	}
	int Q;
	scanf("%d",&Q);
	for(i=0;i<Q;i++)
	{
		char op;
		scanf(" %c",&op);
		
	    if(op == 'D')
		{
			int x;
			scanf("%d",&x);
			erase(&root,x);
		}
		else if(op == 'I')
		{
			int x,y;
			scanf("%d",&x);
			scanf("%d",&y);
			insert(&root,x,y);
		}
		else if(op == 'R'&&key==1)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			erase(&root,x*key);
			insert(&root,x,y);
		}
		else if(op == 'Q'&&key)
		{
			int x,y;
			scanf("%d",&x);
			scanf("%d",&y);
			printf("%d\n",query(&root,x,y));
		}
	}
	return 0;
}