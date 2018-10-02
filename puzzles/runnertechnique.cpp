
#include<iostream>
#include<cstdlib>
using namespace std;


struct node
{
    int data;
    struct node* next;
};

/* Function to get the middle of the linked list*/
void printMiddle( node *head)
{
    int countit = 0;
     node *mid = head;

    while (head != NULL)
    {

        if (countit & 1)
            mid = mid->next;

        ++countit;
        head = head->next;
    }

    /* if empty list is provided */
    if (mid != NULL)
        cout<< mid->data;
}


void push(node** head_ref, int new_data)
{

     node* new_node =( node*) malloc(sizeof( node));


    new_node->data  = new_data;

    new_node->next = (*head_ref);


    (*head_ref)    = new_node;
}


/* Driver program to test above function*/
int main()
{
     node* head = NULL;
    int data=0;
cout<<"enter data, press -1 to end insertion"<<endl;
   while (data!=-1)
    {   cin>>data;
        push(&head, data);

    }


        printMiddle(head);

    return 0;
}
