#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <algorithm>

#define initSTACKSIZE 3

stack::stack(){
	this->top=0;
    this->ssize=initSTACKSIZE;
	this->dane = new int [this->ssize];
	assert(this->dane);
}

stack::~stack(){
    delete[] this->dane;
}

void stack::clear(){
	this->top=0;
}

void stack::push(int a){

	if (this->top>=this->ssize){
	    int tempstacksize = this->ssize;
            this->ssize *= 2;
	    int *tempdane = new int [tempstacksize];
	    std::copy(this->dane, this->dane+tempstacksize, tempdane);
	    delete this->dane;
	    this->dane = new int[this->ssize];
	    std::copy(tempdane, tempdane+tempstacksize, this->dane);
        }
	this->dane[this->top++]=a;
}

int stack::pop(){
	if (this->isEmpty()){
		this->~stack();
		assert(this->top>0);
	}
	return this->dane[--this->top];
}

bool stack::isEmpty(){
	return (this->top==0 ? true : false);
}
