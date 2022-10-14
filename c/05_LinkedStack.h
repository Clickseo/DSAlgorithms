// #pragma once
#ifndef __ListStack_H__
#define __ListStack_H__

typedef int element;
typedef struct _stackNode {
	element			data;
	struct _stackNode*	link;
}stackNode;

typedef struct _LinkedStack {
	stackNode* top;
}LinkedStack;

#endif

LinkedStack*	stackCreate(void);
void		stackDestroy(LinkedStack* s);
stackNode*	makeStackNode(int data);
void		push(LinkedStack* s, element data);
element		pop(LinkedStack* s);
element		peek(LinkedStack* s);
_Bool		sEmpty(LinkedStack* s);
void		printStack(LinkedStack* s);
