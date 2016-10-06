/*
	Name: stack.cpp
	Author: Ashwin Krishnan
	Date: 06-10-16 02:17
	Description: simple stack implemenation 
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct stack
{
	char* content;     //Pointer to char array containing data
	int top; 	   	   //Top of stack
	int max_size; 	   //Maxsize of stack
	int current_size;  //Current size of stack
};

//Intialize stack 
void init_stack(stack *s1, int max_size)
{
	s1->content = (char*)malloc(sizeof(char) * max_size); //Allocate enough space to hold "max_size" elements in stack
	s1->max_size = max_size;
	s1->top = -1;		  	
	s1->current_size = 0; 
}

//Pop and Push functions for stack
//-------------------------------

//Push the element "data" onto stack "s1"
void push(stack *s1, char data)
{
	char* s_head;   //First element in content array at index [0]
	
	//Check if stack is full
	if(s1->current_size == s1->max_size)
	{
		cout << "Error: Stack is full" << endl;
		
		exit(0);
	}
	
	else
	{
		//Add data to the content array at position (top + 1)
		s_head = s1->content;
		s1->top ++; 
		
		//s_head[s1->top] = data;
		*(s_head + s1->top) = data; //Pushing data onto top of the stack
		s1->current_size ++;
		
		cout << "Success: Element pushed -> " << data << endl;
		 
	}
}

//Pop the top element from the stack "s1"
char pop(stack *s1)
{
	char top_element;
	//If stack is empty exit with error
	if(s1->current_size == 0)
	{
		cout << "Error: Stack is empty" << endl;
		exit(0);
	}
	
	else
	{
		top_element = *(s1->content + s1->top);
		s1->top --;
		s1->current_size--;
	}		
	
	cout << "Success: Stack popped  " << top_element << endl;
	return top_element;
}


void print_elements(stack *s1)
{
	char* content_array = s1->content;
	
	cout << "Stack: " ;
	for(int i = 0; i <= s1->top; i++)
	{
		cout << content_array[i] ;
		
		if(i != s1->top)
		cout << " -> " ;
	}
	cout << "\n";
}

int main()
{
	//Testing stack implementation
	
	cout << "Testing stack implementation"<< endl;
	cout << "----------------------------" << endl;
	
	stack *s1 = (stack*) malloc(sizeof(stack));
	int max_size = 5;
	
	init_stack(s1,max_size);

	push(s1,'A');
	push(s1,'B');
	push(s1,'C');
	
	print_elements(s1);
	
	pop(s1);
	pop(s1);
	pop(s1);
	pop(s1);
	

	print_elements(s1);
	
	free(s1);
	
	return 0;
}
