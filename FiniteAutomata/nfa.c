/*
 * nfa.c
 *
 *  Created on: Sep 15, 2020
 *      Author: chris
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nfa.h"
#include "IntHashSet.h"

typedef struct Node *Node;

#define TRUE 1
#define FALSE 0

//Structure of Node
struct Node{
	int value;
	bool is_accepting;
	IntHashSet next_state;
};

//New Node
Node new_Node (int value){
	Node this = (Node)malloc(sizeof(struct Node));
	if (this == NULL){
		return NULL;
	}
	this->value = value;
	this->is_accepting = false;
	this->next_state = new_IntHashSet(10);
	return this;
}

//Make NFA structure
struct NFA {
	int nstates;
	IntHashSet current_states;
	int accepting_state;
	Node** transition_table;
};

//Make new NFA
NFA new_NFA(int nstates){
	NFA this = (NFA)malloc(sizeof(struct NFA));
	if(this == NULL){
		return NULL;  //Out of memory
	}
	this->nstates = nstates;
	this->transition_table = (Node**)malloc(this->nstates*sizeof(Node*));
	for (int i=0; i<this->nstates;i++){
		this->transition_table[i] = (Node*)malloc(128*sizeof(struct Node));
	}
		for (int i =0; i<this->nstates; i++){
			for (int j=0; j<128; j++){
			Node node =new_Node(j);
			this->transition_table[i][j] = node;
		}
  }
	this->current_states = new_IntHashSet(10);
	IntHashSet_insert(this->current_states,0);
	this->accepting_state = 0;
	return this;
}

//Free memory
extern void NFA_free(NFA nfa){
	free(nfa);
}

extern int NFA_get_size(NFA nfa){
	return nfa->nstates;
}

extern IntHashSet NFA_get_transitions(NFA nfa, int state, char sym){
	int sym_int = sym;  //ASCII value of character
	return nfa->transition_table[state][sym_int]->next_state;
}

extern void NFA_add_transition(NFA nfa, int src, char sym, int dst){
	int sym_int = sym;  //ASCII value of character
	IntHashSet_insert(nfa->transition_table[src][sym_int]->next_state, dst);
}

extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst){

}

extern void NFA_add_transition_all(NFA nfa, int src, int dst){
	for (int j=0; j<128; j++){
		IntHashSet_insert(nfa->transition_table[src][j]->next_state,dst);
	}
}

extern void NFA_set_accepting(NFA nfa, int state){
	nfa->accepting_state = state;
}

extern int  NFA_get_accepting(NFA nfa){
	return nfa->accepting_state;
}

extern bool NFA_execute(NFA nfa, char *input){
    int i = 0;
    while (input[i] != '\0'){
    IntHashSet states = new_IntHashSet(10);
    IntHashSetIterator it = IntHashSet_iterator(nfa->current_states);
    while(IntHashSetIterator_hasNext(it)){
	int iterator_of_states;
	iterator_of_states = IntHashSetIterator_next(it);
	printf("NFA current state ---> %d\n", iterator_of_states);
	IntHashSet_union(states, NFA_get_transitions(nfa,iterator_of_states,input[i]));
	}
    nfa->current_states = states;
    i+=1;
    }
    if (IntHashSet_lookup(nfa->current_states, nfa->accepting_state)){
      printf("%s\n", "It matches!");
    }
    else{
     printf("%s\n", "It does not match :(");
    }
  return IntHashSet_lookup(nfa->current_states, nfa->accepting_state);
}

extern void NFA_print(NFA nfa, char c){

}







