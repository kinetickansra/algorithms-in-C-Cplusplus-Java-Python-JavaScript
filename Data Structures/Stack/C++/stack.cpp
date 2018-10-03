#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
	int info;
	struct node *link;
}*top=NULL;

void push(int item);
int pop();
int isEmpty();
void display();

int main()
{
	int choice,item,n,i;
	
	while(1)
	{
	
	   cout<<"\n 1. Press 1 to push the elements in the stack";
	   cout<<"\n 2. Press 2 to pop the elements in the stack";
       cout<<"\n 3. Press 3 to display all the elements in the stack";
       cout<<"\n 4. Press 4 to quit";
    
	   cout<<"\n Enter your choice";
	   cin>>choice;
	   
	   switch(choice)
	   {
	   	case 1:
	   		cout<<"\n Enter the number of items you want to push";
	   		cin>>n;
	   		cout<<"\n Enter the items :";
	   		
	   		for(i=0;i<n;i++)
	   		{
			cin>>item;   
	   		push(item);
	   	    }  
			break;
	   		
	   	case 2:
		   	cout<<"\n Enter the number of items you want to pop";
	   		cin>>n;
	   		for(i=0;i<n;i++)
	   		{
	   			int popped_number;
	   			popped_number=pop();
	   			cout<<"\n Popped item is :"<<popped_number;
			   }
			break;
			
		case 3:
		     display();
			 break;
			 
		case 4:
		    exit(1);
		
		default:
		cout<<"\n Enter a valid choice";
		
		}/*End of switch*/
	
	
	} /*End of while*/
	
	
}/*End of main*/

void push(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	
	if(tmp==NULL)
	{
		cout<<"\n Stack overflow";
		return ;
	}
	
    tmp->info=item;
    tmp->link=top;
    top=tmp;
}/* End of push*/

int pop()
{
	struct node *tmp;
	int item;
	if(isEmpty())
	{
		cout<<"\n Stack underflow";
		exit(1);
		
	}
	tmp=top;
	item=tmp->info;
	top=top->link;
	free(tmp);
	return item;
}/*End of pop*/

int isEmpty()
{
	if(top==NULL)
	return 1;
	
	else 
	return 0;
}/* End of isEmpyu*/

void display()
{
	struct node *ptr;
	ptr=top;
	
	if(isEmpty())
	{
		cout<<"\n Stack is empty";
		return;
	}
	
	cout<<"\n Stack elements:\n";
	
	while(ptr!=NULL)
	{
		cout<<"\n"<<ptr->info;
		ptr=ptr->link;
	}
	cout<<endl;
	
}/*End of display*/
