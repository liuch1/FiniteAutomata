/*
 * questions.c
 *
 *  Created on: Sep 20, 2020
 *      Author: chris
 */

#include <stdio.h>
#include <stdlib.h>
#include "dfa.h"
#include "nfa.h"
#include "nfa2dfa.h"

extern void printWelcome() {
	  printf("%s\n", " ");
	  printf("%s\n", "Congrats on your result.");
	  printf("%s\n", "IMPORTANT: Make sure to press enter first, and then you can choose from the menu again!");
	  printf("%s\n", "----------------------------------------------------------------------------------");
	  printf("%s\n", "-Finite Automata Menu-");
	  printf("%s\n", "1. Deterministic Finite Automata");
	  printf("%s\n", "2. Non-Deterministic Finite Automata");
	  printf("%s\n", "3. Converting Deterministic Finite Automata to Non-Deterministic Finite Automata");
	  printf("%s\n", "0. Quit");
	  printf("%s\n", "Enter 1, 2, 3, or 0.");
}


extern void dfa1(){
  DFA dfa1 = new_DFA(6);

    //set transitions
    DFA_set_transition_all(dfa1, 1, 1);
    DFA_set_transition(dfa1, 0, 'h', 1);
    DFA_set_transition(dfa1, 1, 'a', 2);
    DFA_set_transition(dfa1, 2, 'p', 3);
    DFA_set_transition(dfa1, 3, 'p', 4);
    DFA_set_transition(dfa1, 4, 'y', 5);

    DFA_set_accepting(dfa1, 5, 1);

    printf("%s", "Enter a string! Test if it works.");
    char string1[256];
    fflush(stdout);
    scanf("%s",string1);
    printf("String entered: %s\n", string1);
    printf("%d\n", DFA_execute(dfa1, string1));

    DFA_free(dfa1);
}

extern void dfa2(){
  DFA dfa2 = new_DFA(4);

    //set transitions
    DFA_set_transition(dfa2, 0, '9', 1);
    DFA_set_transition(dfa2, 1, '9', 2);
    DFA_set_transition(dfa2, 2, '9', 3);
    DFA_set_transition_all(dfa2, 3, 3);
    DFA_set_accepting(dfa2, 3, 1);

    printf("%s", "Enter a string! Test if it works.");
    char string2[256];
    fflush(stdout);
    scanf("%s",string2);
    printf("String entered: %s\n", string2);
    printf("%d\n", DFA_execute(dfa2, string2));

    DFA_free(dfa2);
}

extern void dfa3(){
   DFA dfa3 = new_DFA(2);
    DFA_set_transition(dfa3, 0, '0' , 0);
    DFA_set_transition(dfa3, 0, '1', 1);
    DFA_set_transition(dfa3, 1, '1', 0);
    DFA_set_transition(dfa3, 1, '0', 1);
    DFA_set_accepting(dfa3, 0, 1);

    printf("%s", "Enter a string! Test if it works.");
    char string3[256];
    fflush(stdout);
    scanf("%s",string3);
    printf("String entered: %s\n", string3);
    printf("%d\n", DFA_execute(dfa3, string3));

    DFA_free(dfa3);
}

extern void dfa4(){
  DFA dfa4 = new_DFA(4);
     DFA_set_transition(dfa4, 0, '1', 1);
     DFA_set_transition(dfa4, 0, '0', 3);
     DFA_set_transition(dfa4, 1, '1', 0);
     DFA_set_transition(dfa4, 1, '0', 2);
     DFA_set_transition(dfa4, 2, '1', 3);
     DFA_set_transition(dfa4, 2, '0', 1);
     DFA_set_transition(dfa4, 3, '1', 2);
     DFA_set_transition(dfa4, 3, '0', 0);
     DFA_set_accepting(dfa4, 3, 1);

     printf("%s", "Enter a string! Test if it works.");
	 char string4[256];
	 fflush(stdout);
	 scanf("%s",string4);
	 printf("String entered: %s\n", string4);
	 printf("%d\n", DFA_execute(dfa4, string4));

     DFA_free(dfa4);
}

extern void dfa5(){
  DFA dfa5 = new_DFA(6);

    //set transitions
    DFA_set_transition(dfa5, 0, 'm', 1);
    DFA_set_transition(dfa5, 1, 'o', 2);
    DFA_set_transition(dfa5, 2, 'o', 3);
    DFA_set_transition(dfa5, 3, 'o', 4);
    DFA_set_transition(dfa5, 4, 'o', 5);
    DFA_set_transition_all(dfa5, 5, 5);
    DFA_set_accepting(dfa5, 5, 1);

    printf("%s", "Enter a string! Test if it works.");
    char string5[256];
    fflush(stdout);
    scanf("%s",string5);
    printf("String entered: %s\n", string5);
    printf("%d\n", DFA_execute(dfa5, string5));

    DFA_free(dfa5);
}


extern void execute_dfa(){
  printf("%s\n", "Part 1 -- Deterministic Finite Automata");
  printf("%s\n", "1. Exactly the string 'happy'.");
  printf("%s\n", "2. Any string that starts with the 999.");
  printf("%s\n", "3. Binary input with an even number of 1's.");
  printf("%s\n", "4. Binary input with an odd number of 0's and even number of 1's.");
  printf("%s\n", "5. String that starts with 'moooo'.");
  printf("%s\n", "Enter your choice 1, 2, 3, 4, or 5!");

  char ch;
  fflush(stdout);
  scanf("%c%*c", &ch);
  if (ch == '1'){
    dfa1();
    printWelcome();
  }
  else if (ch == '2'){
    dfa2();
    printWelcome();
  }
  else if (ch == '3'){
    dfa3();
    printWelcome();
  }
  else if (ch == '4'){
    dfa4();
    printWelcome();
  }
  else if (ch == '5'){
    dfa5();
    printWelcome();
  }

}

extern void nfa1(){

    NFA nfa1 = new_NFA(4);
    NFA_set_accepting(nfa1, 3);
    NFA_add_transition_all(nfa1, 0, 0);
    NFA_add_transition(nfa1, 0, 'i', 0);
    NFA_add_transition(nfa1, 0, 'i', 1);
    NFA_add_transition(nfa1, 1, 'n', 2);
    NFA_add_transition(nfa1, 2, 'g', 3);

    char string1[256];
    printf("%s\n", "Enter a string! Test if it works.");
    fflush(stdout);
    scanf("%s", string1);
    printf("Scanned string: %s\n", string1);
    printf("%d\n", NFA_execute(nfa1, string1));
}

extern void nfa2(){
   NFA nfa2 = new_NFA(4);
    NFA_set_accepting(nfa2, 3);
    NFA_add_transition_all(nfa2, 0, 0);
    NFA_add_transition(nfa2, 0, 'i', 1);
    NFA_add_transition(nfa2, 0, 'n', 2);
    NFA_add_transition(nfa2, 2, 'g', 3);
    NFA_add_transition_all(nfa2, 3, 3);

    char string2[256];
    printf("%s\n", "Enter a string! Test if it works.");
    fflush(stdout);
    scanf("%s", string2);
    printf("Scanned string: %s\n", string2);
    printf("%d\n", NFA_execute(nfa2, string2));
}

extern void nfa3(){
  NFA nfa3 = new_NFA(12);
    NFA_add_transition_all(nfa3, 0, 0);
    NFA_add_transition_all(nfa3, 1, 1);
    NFA_add_transition_all(nfa3, 2, 2);
    NFA_add_transition_all(nfa3, 3, 3);
    NFA_add_transition_all(nfa3, 4, 4);
    NFA_add_transition_all(nfa3, 5, 5);
    NFA_add_transition_all(nfa3, 6, 6);
    NFA_add_transition_all(nfa3, 7, 7);
    NFA_add_transition_all(nfa3, 8, 8);
    NFA_add_transition_all(nfa3, 9, 9);
    NFA_add_transition_all(nfa3, 10, 10);
    NFA_add_transition_all(nfa3, 11, 11);

    NFA_add_transition(nfa3, 0, 'w', 1);
    NFA_add_transition(nfa3, 1, 'w', 11);
    NFA_add_transition(nfa3, 0, 'a', 2);
    NFA_add_transition(nfa3, 2, 'a', 11);
    NFA_add_transition(nfa3, 0, 's', 3);
    NFA_add_transition(nfa3, 3, 's', 11);
    NFA_add_transition(nfa3, 0, 'h', 4);
    NFA_add_transition(nfa3, 4, 'h', 11);
    NFA_add_transition(nfa3, 0, 'i', 5);
    NFA_add_transition(nfa3, 5, 'i', 11);
    NFA_add_transition(nfa3, 0, 'g', 6);
    NFA_add_transition(nfa3, 6, 'g', 11);
    NFA_add_transition(nfa3, 0, 't', 7);
    NFA_add_transition(nfa3, 7, 't', 11);
    NFA_add_transition(nfa3, 0, 'o', 8);
    NFA_add_transition(nfa3, 8, 'o', 11);
    NFA_add_transition(nfa3, 0, 'n', 9);
    NFA_add_transition(nfa3, 9, 'n', 10);
    NFA_add_transition(nfa3, 10, 'n', 11);

    NFA_set_accepting(nfa3, 11);

    char string3[256];
    printf("%s\n", "Enter a string! Test if it works.");
    fflush(stdout);
    scanf("%s", string3);
    printf("Scanned string: %s\n", string3);
    printf("%d\n", NFA_execute(nfa3, string3));
}

extern void nfa4(){
   NFA nfa4 = new_NFA(6);

   NFA_set_accepting(nfa4, 5);

    NFA_add_transition_all(nfa4, 0, 0);

    NFA_add_transition(nfa4, 0, 'q', 1);
    NFA_add_transition(nfa4, 0, 'u', 2);
    NFA_add_transition(nfa4, 0, 'a', 3);
    NFA_add_transition(nfa4, 0, 'c', 4);
    NFA_add_transition(nfa4, 4, 'k', 5);

    char string4[256];
    printf("%s\n", "Enter a string! Test if it works.");
    fflush(stdout);
    scanf("%s", string4);
    printf("Scanned string: %s\n", string4);
    printf("%d\n", NFA_execute(nfa4, string4));
}



extern void execute_nfa(){
  printf("%s\n", "Part 2 -- Non-Deterministic Finite Automata");
  printf("%s\n", "1. String ending in 'ing' ");
  printf("%s\n", "2. Strings containing 'ing' ");
  printf("%s\n", "3. For each letter in 'washington' more than one. For 'n' more than 2.");
  printf("%s\n", "4. Strings ending in 'quack'");
  printf("%s\n", "Enter 1, 2, 3, or 4!");
  char ch2;
  fflush(stdout);
  scanf("%c%*c", &ch2);
  if (ch2 == '1'){
    nfa1();
    printWelcome();
  }
  else if (ch2 == '2'){
    nfa2();
    printWelcome();
  }
  else if (ch2 == '3'){
    nfa3();
    printWelcome();

  }
  else if (ch2 == '4'){
    nfa4();
    printWelcome();
  }
}

extern void execute_nfa_dfa(){
  printf("%s\n", "Part 3 -- Non-Deterministic Finite Automata to Finite Deterministic Automata");
  printf("%s\n", "1. Strings ending in 'ing' ");
  printf("%s\n", "2. Strings containing 'ing' ");
  char ch3;
  printf("%s\n", "Enter 1 or 2!");
  fflush(stdout);
  scanf("%c%*c", &ch3);

  if (ch3 == '1'){

    NFA nfa1 = new_NFA(4);
    NFA_set_accepting(nfa1, 3);
    NFA_add_transition_all(nfa1, 0, 0);
    NFA_add_transition(nfa1, 0, 'i', 0);
    NFA_add_transition(nfa1, 0, 'i', 1);
    NFA_add_transition(nfa1, 1, 'n', 2);
    NFA_add_transition(nfa1, 2, 'g', 3);

    char string1[256];
    printf("%s\n", "Enter a string! Test if it works.");
    fflush(stdout);
    scanf("%s", string1);
    printf("Scanned string: %s\n", string1);

    printf("%s\n", "-----------------------------");

    DFA dfa_nfa1 = NFA_to_DFA(nfa1);
    printf("%d\n", DFA_execute(dfa_nfa1, string1));
    printWelcome();
  }
  else if (ch3 == '2'){

    NFA nfa2 = new_NFA(4);
    NFA_set_accepting(nfa2, 3);
    NFA_add_transition_all(nfa2, 0, 0);
    NFA_add_transition(nfa2, 0, 'i', 1);
    NFA_add_transition(nfa2, 0, 'n', 2);
    NFA_add_transition(nfa2, 2, 'g', 3);
    NFA_add_transition_all(nfa2, 3, 3);

    char string2[256];
    printf("%s\n", "Enter a string! Test if it works.");
    fflush(stdout);
    scanf("%s", string2);
    printf("Scanned string: %s\n", string2);

    printf("%s\n", "-----------------------------");

    DFA dfa_nfa2 = NFA_to_DFA(nfa2);
    printf("%d\n", DFA_execute(dfa_nfa2, string2));
    printWelcome();
  }

}

