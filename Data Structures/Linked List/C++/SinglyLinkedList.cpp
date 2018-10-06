/**
 * SinglyLinkedList.cpp
 * Implementation of Singly Linked List Class
 *
 * @author <a href="mailto:yripila@gmail.com">Ali Piry</a>
 *
 */

#include "SinglyLinkedList.hpp"
#include <iostream>

void LinkedList::createNode(int value)
{
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;

  if(head == NULL)
  {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

void LinkedList::display()
{
  node *temp = new node;
  temp = head;
  while(temp != NULL)
  {
    std::cout << temp->data << "\t";
    temp = temp->next;
  }
}

void LinkedList::insertionAtStart(int value)
{
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  head = temp;
}

void LinkedList::insertionAtEnd(int value)
{
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;
  tail->next = temp;
  tail = temp;
}

void LinkedList::insertionParticularPosition(int position, int value)
{
  node *previous = new node;
  node *current = new node;
  node *temp = new node;
  current = head;

  for(int i = 1; i < position; i++)
  {
    previous = current;
    current = current->next;
  }

  temp->data = value;
  previous->next = temp;
  temp->next = current;
}

void LinkedList::deletionFromStart()
{
  node *temp = new node;
  temp = head;
  head = head->next;
  delete temp;
}

void LinkedList::deletionFromEnd()
{
  node *current = new node;
  node *previous = new node;
  current = head;

  while (current->next != NULL)
  {
    previous = current;
    current = current->next;
  }
  tail = previous;
  previous->next = NULL;
  delete current;
}

void LinkedList::deletionOfParticularPosition(int position)
{
  node *current = new node;
  node *previous = new node;
  current = head;

  for(int i = 1; i < position; i++)
  {
    previous = current;
    current = current->next;
  }

  previous->next = current->next;
}
