/*
 * dfa.c
 *
 *  Created on: Sep 15, 2020
 *      Author: chris
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"

typedef struct Node *Node;

#define TRUE 1
#define FALSE 0

//Structure of Node
struct Node{
  int value;
  int next_state;
};

//New node DFA
Node new_DFA_Node (int value){
  Node this = (Node)malloc(sizeof(struct Node));
  if (this == NULL){
    return NULL;
  }
  this->value = value;
  this->next_state = 0;
  return this;
}

//Structure of DFA
struct DFA {
  int nstates;
  int current_state;
  int accepting_state;
  Node** transition_table;

};

//New DFA
DFA new_DFA(int nstates){
  DFA this = (DFA)malloc(sizeof(struct DFA));
  if (this == NULL){
    return NULL;
  }
  this->nstates = nstates;
  this->transition_table = (Node**)malloc(this->nstates*sizeof(Node*));
  for (int i=0; i<this->nstates;i++){
    this->transition_table[i] = (Node*)malloc(128*sizeof(struct Node));
  }
  return this;

}

//Free memory
extern void DFA_free(DFA dfa){
  free(dfa);
}

extern int DFA_get_size(DFA dfa){
 return dfa->nstates;
}

extern int DFA_get_transition(DFA dfa, int src, char sym){
  int sym_int = sym;
  return dfa->transition_table[src][sym_int]->next_state;

}

extern void DFA_set_transition(DFA dfa, int src, char sym, int dst){
  int sym_int = sym;
  Node node = new_DFA_Node(sym_int);
  dfa->transition_table[src][sym_int] = node;
  node->next_state = dst;
}

extern void DFA_set_transition_str(DFA dfa, int src, char *str, int dst){

}

extern void DFA_set_transition_all(DFA dfa, int src,int dst){
	for (int j=0; j<128;j++){
	if (dfa->transition_table[src][j] == NULL){
		Node node = new_DFA_Node(src);
		dfa->transition_table[src][j] = node;
		node->next_state = dst;
	}
  }
}

extern void DFA_set_accepting(DFA dfa, int state, bool value){
	dfa->accepting_state = state;
}

extern bool DFA_get_accepting(DFA dfa, int state){
	if (dfa->accepting_state == state){
		return TRUE;
	}
	else{
		return FALSE;
    }
}


extern bool DFA_execute(DFA dfa, char *input){
	int i = 0;
	while (input[i]!='\0'){
    int i_c = input[i];
    if (dfa->transition_table[dfa->current_state][i_c] == NULL){
      printf("%s\n", "It doesn't match :(");
	return 0;
      }
	dfa->current_state = DFA_get_transition(dfa,dfa->current_state, input[i]);
	DFA_print(dfa, input[i]);
	i+=1;
	}
	if (dfa->accepting_state == dfa->current_state){
		printf("%s\n", "It matches!!");
	}
    else{
    	printf("%s\n", "It doesn't match :(");
  }
	return (dfa->accepting_state == dfa->current_state);
}


extern void DFA_print(DFA dfa, char c){
	printf("--%c-->( %d )", c, dfa->current_state);
}
