#include <iostream>
#ifndef NODE_H
#define NODE_H

class Node{

public:
  Node();
  ~Node();
  Node* getNextLeft();
  Node* getNextRight();
  void setNextLeft(Node* newLeft);
  void setNextRight(Node* newRight);
  void setValueLeft(int value);
  void setValueRight(int value);
  int getValue();
private:
  Node* nextLeft;
  Node* nextRight;
  int value;






};

#endif
