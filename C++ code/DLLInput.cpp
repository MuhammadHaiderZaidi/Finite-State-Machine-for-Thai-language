#include "DLLInput.h"


DLLInput::DLLInput(void):head(NULL),tail(NULL){}


DLLInput::~DLLInput(void)
{
	delete head;
	head = NULL;
	delete tail;
	tail = NULL;
}

void DLLInput::addNode( wchar_t data[] )
{
	node* newNode = new node;
	newNode->sapce = false;
	for(int i=0;i<3;i++) 
		newNode->output[i] = data[i];

	if(head==NULL)
	head = newNode;
	
	else{
		newNode->prev=tail;
		tail->next = newNode;	
		}
	newNode->next = NULL;
	tail = newNode;
}


node*  DLLInput::getTail(){return tail;}

node* DLLInput::getHead(){return head;}

wchar_t*  DLLInput::getData(node* temp){return temp->output; }

void  DLLInput::addSpace(node* temp){ temp->sapce = true; }

bool  DLLInput:: isSpace(node* temp){return temp->sapce;}