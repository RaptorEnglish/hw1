/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit  non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>

/* Add a prototype  a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // base case to return if in is null
  if (in == nullptr) {
    return;
  }

  // take out first node of in and set next to nullptr to reset it
  Node* curr_val = in;
  in = in->next;

  // reset nullptr so it can point at evens or odds
  curr_val->next = nullptr;

  if (curr_val->value % 2 == 1) {  // odd val

    if (odds == nullptr) {  // edge case to handle initial null
      odds = curr_val;
    } else {  // update curr_val to point to curr odds
      curr_val->next = odds;
      odds = curr_val;
    }
  } else { // even val

    if (evens == nullptr) {  // handle initial even null value
      evens = curr_val;
    } else {  // insert node into evens list
      curr_val->next = evens;
      evens = curr_val;
    }
  }

  // call recursive function with new in
  return split(in, odds, evens);
}

/* If you needed a helper function, write it here */
