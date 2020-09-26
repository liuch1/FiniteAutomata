/*
 * nfa2dfa.c
 *
 *  Created on: Sep 15, 2020
 *      Author: chris
 */


#include <stdio.h>
#include <stdlib.h>
#include "nfa.h"
#include "dfa.h"
#include "nfa2dfa.h"

int my_pow (int a, int b){
  int size = 1;
  for (int i=0; i<a; i++){
    size = size*b;
  }
  return size;
}

//Convert NFA to DFA
extern DFA NFA_to_DFA(NFA nfa){
  int dfa_size = my_pow(NFA_get_size(nfa),2);
  printf("size: %d\n", dfa_size);
  DFA dfa = new_DFA(dfa_size);
  if(NFA_get_accepting(nfa)== 0){
    //printf("%s\n", "goes here");
    DFA_set_accepting(dfa,0,true);
    }
  IntHashSet s = new_IntHashSet(100);
  IntHashSet_insert(s,0);
  IntHashSet list_of_sets [dfa_size];
  list_of_sets[0] = s;
  int stateN=0;
  for (int k=0; k<DFA_get_size(dfa);k++){
     if (k>stateN){
	      break;
	    }
      for (int i=0; i<128; i++){
	//IntHashSet DFA_states = s;
	IntHashSet DFA_sets = list_of_sets[k];
	IntHashSetIterator NFA_sets = IntHashSet_iterator(DFA_sets);
	IntHashSet my_set = new_IntHashSet(100);
	while (IntHashSetIterator_hasNext(NFA_sets)){

	    char c1 = i;
	    IntHashSet_union(my_set, NFA_get_transitions(nfa,IntHashSetIterator_next(NFA_sets),c1));

	}
	free (NFA_sets);
	//if state already exists
	bool state_exists = false;

	if (IntHashSet_isEmpty(my_set) == false){

	  for (int j=0; j<(k+1); j++){
	    if (IntHashSet_equals(my_set, list_of_sets[j])){
	      char c = i;
	      DFA_set_transition(dfa, k, c, j);    //i is the character
	      state_exists = true;
	      }
	  }
	    if(state_exists == false){
	      stateN++;
	      char c2 = i;
	      DFA_set_transition(dfa,k,c2,stateN);
	      list_of_sets[stateN] = my_set;
	      IntHashSetIterator it;
	      it = IntHashSet_iterator(my_set);
	      while(IntHashSetIterator_hasNext(it)){
		int statenum = IntHashSetIterator_next(it);
		// if there is an accepting state, accept NFAsets
		if (NFA_get_accepting(nfa) ==  statenum){
		  printf("statenums %d\n",statenum);
		  printf("stateNs %d\n", stateN);
		  DFA_set_accepting(dfa, stateN, true);
		}
	      }
	      free(it);

	    }
	}
      }
    }

  return dfa;
}

