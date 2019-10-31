#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class list{
	private:
		node *head;
	public:
		list(){
			head=NULL;
		}
};

int main()
{
	node *head;
	head=NULL;
	int n,t,pos,repeat,value;
	label:
	cout<<"\n ------------"<<endl;
	cout<<" LINKED LIST "<<endl;
	cout<<" ------------"<<endl;
	cout<<"\n Select the operation number you want to perform:\n"<<endl;
	cout<<" 1. Insert data at beginning of the link list. \n";
	cout<<" 2. Insertion of a data at a particular position. \n";
	cout<<" 3. Insert data at end of the link list. \n";
	cout<<" 4. Deletion of a node at a particular position. \n";
	cout<<" 5. Print the link list. \n";
	cout<<" 6. Sort the link list. \n";
	cout<<" 7. Reversing a link list. \n";
	cout<<" 8. Exit. \n";
	cin>>t;

switch (t)
{
	case 1://at beginnning
		{
			cout<<"Enter the data : ";
			cin>>value;
			node *temp = new node ;
			temp->data = value;
			temp->next = NULL;

			if(head == NULL)
			{
				head= temp;
				temp=NULL;
			}
			else
			{
				temp->next = head;
				head = temp;
			}
		}
		goto label;
		
	case 2://at position
	{	
		int count=1;
		int inc;
		cout<<"Enter the position where you want to insert: ";
		cin>>pos;
		{	
			node *ptr = new node;
			ptr = head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
				count++;
			}
		}
		inc=count+1;
		cout<<inc;
		if(pos<=inc)
		{
		
			if (pos == 1)
			{
				cout<<"Enter the data in the node: ";
				cin>>value;
				node *temp = new node ;
				temp->data = value;
				temp->next = head;
				head = temp;
			}
	
			else
			{
				cout<<"Enter the data in the node: ";
				cin>>value;
				node *temp = new node;
				node *prev = new node;
				node *curr = new node;
	
				curr = head;
				for(int i=1;i<pos;i++)
				{
					prev=curr;
					curr=curr->next;
				}
				temp->data= value;
				prev->next= temp;
				temp->next= curr;
			}
		}
		else
		{
			cout<<"INVALID POSITION!";
		}
	}
		goto label;
	
	case 3:// at end
		{
			cout<<"Enter the data : ";
			cin>>value;
			if (head==NULL)
			{
				cout<<"\nThe list is empty.\n";
			}
			else
			{
				node *temp = new node;
				node *curr = new node;
				temp->data = value;
				temp->next = NULL;
				curr=head;
				
				while(curr->next!=NULL)
				{
					curr= curr->next;
				}
				
				curr->next = temp;
				temp->next = NULL;
			}
		}
		goto label;

	case 4: //delete node
	{
		int count=1;
		cout<<"Enter the position you want to delete: ";
		cin>>pos;
		node *check = new node;
		check = head;
		
			
			while(check->next!=NULL)
			{
				check= check->next;
				count ++;
			}
			
		if (pos<=count && pos>0)
		{
		
			if  (pos == 1)
			{
				node *curr = new node;
				curr = head;
				head = curr->next;
				cout<<"\nDeletion successful";
			}
	
			else
			{
				node *prev = new node;
				node *curr = new node;
	
				curr = head;
				for(int i=1;i<pos;i++)
				{
					prev=curr;
					curr=curr->next;
				}
				prev->next = curr->next;
				cout<<"\nDeletion sucessful!";
			}
		}
		else
		{
			cout<<"INVALID POSITION!";
		}
	}
	goto label;
	
	case 5: //print linklist
		{
			node *temp=new node;
			temp=head;
				cout<<endl;
			while(temp!=NULL)
			{
				cout<<temp->data<<"  ";
				temp=temp->next;
			}
		}
		goto label;
	
	case 6://sorting
		{
			int box;
			node *temp = new node;
			temp=head;
			node *curr = new node;
			curr = temp->next;
			
			if(head=NULL){
				cout<<"The link list is empty.";
			}
			
			while(temp->next!=NULL)
			{	
				
				while(curr!=NULL)
				{	
					if (temp->data > curr->data)
					{
						box=curr->data;
						curr->data=temp->data;
						temp->data=box;
					}
					curr=curr->next;
				}
				temp=temp->next;
				curr=temp->next;
			}
		} goto label;
	
	case 7: //reversing linklist
	{
			node *temp = new node;
			node *curr = new node;
			node *prev = new node;
			
			if(head == NULL)
			{
				cout<<"List is empty!\n";
			}
			
			else{
				prev = NULL;
				curr = head;
				temp = NULL;
				
				while (curr!=NULL)
				{
					temp = curr->next ;
					curr->next = prev;
					prev = curr;
					curr = temp;
				}
				head = prev;
			}
				
	} goto label;
	
	case 8:
		{
			goto exit;
		}break;
	
	default:
		{
			cout<<"\nINVALID ENTRY!!!";
		}
}
	exit: ;

}
