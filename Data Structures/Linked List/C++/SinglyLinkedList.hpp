/**
 * SinglyLinkedList.hpp
 * Implementation of Singly Linked List Class
 *
 * @author <a href="mailto:yripila@gmail.com">Ali Piry</a>
 *
 */

#pragma once
#define NULL 0

struct node
{
  int data;
  node *next;
};

class LinkedList
{

private:
  node *head, *tail;

public:
  LinkedList()
  {
    head = NULL;
    tail = NULL;
  }

  void createNode(int value);
  void display();
  void insertionAtStart(int value);
  void insertionAtEnd(int value);
  void insertionParticularPosition(int position, int value);
  void deletionFromStart();
  void deletionFromEnd();
  void deletionOfParticularPosition(int position);
};
