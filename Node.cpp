#include <iostream>
#include <string.h>

using namespace std;

Node::Node(){


}

Node::~Node(){

}

//get next left child
Node* Node::getNextLeft(){
  return nextLeft;
}

//get next right child
Node* Node::getNextRight(){
  return nextRight;
}

// set next left child
void Node::setNextLeft(Node* newLeft){
  nextLeft = newLeft;
}

// set next right child
void Node::setNextRight(Node* newRight){
  nextRight = newRight;
}

//get value
int Node::getValue(){
  return value;
}
