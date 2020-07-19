#pragma once
#include<iostream>

struct node{
	wchar_t output [3];
	bool sapce;
	node* next;
	node* prev;
};

class DLLInput
{
private:
	node* head;
	node* tail;
public:
	
	DLLInput(void);
	~DLLInput(void);

	void addNode( wchar_t [] );
	
	node*		getTail();
	node*		getHead();
	wchar_t*	getData(node*);

	void		addSpace(node*);
	bool		isSpace(node*);

};

