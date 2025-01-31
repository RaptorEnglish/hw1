/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>

int main(int argc, char* argv[])
{

  // create nodes
  Node* node1 = new Node(1, nullptr);
  Node* node2 = new Node(2, node1);
  Node* node3 = new Node(3, node2);
  Node* node4 = new Node(4, node3);
  Node* node5 = new Node(5, node4);
  Node* node6 = new Node(6, node5);
  Node* node7 = new Node(7, node6);

  // initialize even and odd arrays
  Node* evens = nullptr;
  Node* odds = nullptr;

  split(node7, odds, evens);
  std::cout <<"hi"<<std::endl;

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;

}
