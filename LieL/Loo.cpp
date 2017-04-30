#include "stdio.h"
#include "malloc.h"
#include "string.h"
typedef struct wordpage
{
	char *eword;
	char *cword;
}wordpage;
typedef struct Node
{
	wordpage *data;
	Node *next;
}Node;

typedef Node *List;
List b[26];
int hash(char *s)
{
	char m = *(s + 0);
	int i = m - 'a';
	return i;

}
void initList()
{
	int current;
	current = hash("ok");
	b[current] = (Node *)malloc(sizeof(Node));
    b[current]->data = (wordpage *)malloc(sizeof(wordpage));
	b[current]->data->eword = "ok";
	b[current]->data->cword = "�õ�";
	b[current]->next = NULL;
	
	current = hash("what");
	b[current] = (Node *)malloc(sizeof(Node));
    b[current]->data = (wordpage *)malloc(sizeof(wordpage));
	b[current]->data->eword = "what";
	b[current]->data->cword = "ʲô";
	b[current]->next = NULL;

	current = hash("nothing");
	b[current] = (Node *)malloc(sizeof(Node));
	b[current]->data = (wordpage *)malloc(sizeof(wordpage));
	b[current]->data->eword = "nothing";
	b[current]->data->cword = "��";
	
	
	b[current]->next = (Node *)malloc(sizeof(Node));
	b[current]->next->data = (wordpage *)malloc(sizeof(wordpage));
	b[current]->next->data->eword = "no";
	b[current]->next->data->cword = "��";
	b[current]->next->next = NULL;

	current = hash("yes");
	b[current] = (Node *)malloc(sizeof(Node));
	b[current]->data = (wordpage *)malloc(sizeof(wordpage));
	b[current]->data->eword = "yes";
	b[current]->data->cword = "�ǵ�";
	b[current]->next = NULL;

}
char * search(char *s)
{
	int k = hash(s);
	List p;
	p = b[k];
	while (p != NULL)
	{
		if (strcmp(p->data->eword, s) == 0)
		{
			return p->data->cword;
			
		}
		p = p->next;

		
	}
	return "û���ҵ�";
}
void listAdd(List head, Node *s)
{
	
	Node *q;
	
	q = head;
	while (q ->next!= NULL)
	{
		 
		q = q->next;

	}
	q->next = s;
	q->next->next = NULL;

	
}
void add(char *s, char *t)
{
	List p;
	Node *q;
	q = (Node *)malloc(sizeof(Node));
	q->data = (wordpage *)malloc(sizeof(wordpage));
	q->data->eword = s;
	q->data->cword = t;
	int m = hash(s);


	p = b[m];
	listAdd(p, q);

}

int main()
{
	char *s;
	char *n;
	s = (char *)malloc(100);
	n = (char *)malloc(100);
	initList();
	printf("������һ������:\n");
	gets_s(s, 100);
	printf("������õ��ʵĺ�����˼:\n");
	gets_s(n, 100);
	add(s, n);
	
	char *t = search(s);
	printf("%s\n", t);
	while (1);
	return 0;
	
}