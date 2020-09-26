/*
 * main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: chris
 */



#include <stdio.h>
#include <stdlib.h>
#include "dfa.h"
#include "nfa.h"
#include "nfa2dfa.h"
#include "questions.h"

void printHi() {
	  printf("%s\n", "Hello! Welcome to my Finite Automata Program.");
	  printf("%s\n", "----------------------------------------------------------------------------------");
	  printf("%s\n", "Finite Automata Menu");
	  printf("%s\n", "1. Deterministic Finite Automata");
	  printf("%s\n", "2. Non-Deterministic Finite Automata");
	  printf("%s\n", "3. Converting Deterministic Finite Automata to Non-Deterministic Finite Automata");
	  printf("%s\n", "0. Quit");
	  printf("%s\n", "Enter 1, 2, 3, or 0.");
}

int main(){
	char a;
	printHi();
	  while (a != '0'){
		fflush(stdout);
		scanf("%c%*c",&a);
			if(a == '1'){
			  execute_dfa();
			}
			else if(a == '2'){
			  execute_nfa();
			}
			else if(a == '3'){
			  execute_nfa_dfa();
			}
			else if (a == '0') {
				break;
	  }
	}
}





























