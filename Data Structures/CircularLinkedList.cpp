//Implementation of Circular Linked List

#include<iostream>
using namespace std;

template<class T>
struct NODE
{
	T info;				//Information in the node.
	NODE<T> *next;			//Points to the next node.
};

typedef NODE<char>* NPTR;

template<class T>
class CLL
{
	NPTR Head;			//Points to the first node.
	public:
		CLL()			//Constructor
		{
			Head=NULL;
		}
		~CLL()			//Destructor
		{
			delete Head;
		}
		NPTR GetNode();						//To get a new node.
		NPTR SearchNode(T);					//To search a node in the linked list.
		void Create(T);						//To create a new linked list.
		void InsertBefore(T, T);			//To insert a new node BEFORE the given node in the linked list.
		void InsertAfter(T, T);				//To insert a new node AFTER the given node in the linked list.
		void DeleteNode(T);					//To delete a node in the linked list.
		void UpdateNode(T, T);				//To update a node of the linked list.
		int Size();							//Returns the size of linked list.
		void Traverse();					//To display the linked list.
		void Reverse();						//To reverse the linked list.
};

template<class T>
NPTR CLL<T>::GetNode()
{
	return new NODE<T>;
}

template<class T>
NPTR CLL<T>::SearchNode(T elt)
{
	NPTR P=Head;
	if (P!=NULL)
	{
		while (P->next!=Head && P->info!=elt)
			P=P->next;
		if (P->info==elt)
			return P;
	}
	return NULL;
}

template<class T>
void CLL<T>::Create(T elt)
{
	NPTR P=GetNode();
	P->info=elt;
	P->next=P;
	Head=P;
	cout<<"\nLinked list successfully created!!!"<<endl<<endl;
}

template<class T>
void CLL<T>::InsertBefore(T new_elt, T before_elt)
{
	NPTR P=SearchNode(before_elt);
	if (P==NULL)
	{
		cout<<"\nERROR!!!\nNode before which you want to insert the new node is not found."<<endl<<endl;
	}
	else
	{
		NPTR Q=GetNode();
		Q->info=new_elt;
		Q->next=P;
		NPTR R=Head;
		while (R->next!=P)
			R=R->next;
		R->next=Q;
		if (P==Head)
			Head=Q;
		cout<<"\nSUCCESS!!!\nNew node is successfully inserted before the given node."<<endl<<endl;		
	}
}

template<class T>
void CLL<T>::InsertAfter(T new_elt, T after_elt)
{
	NPTR P=SearchNode(after_elt);
	if (P==NULL)
	{
		cout<<"\nERROR!!!\nNode after which you want to insert the new node is not found."<<endl<<endl;
	}
	else
	{
		NPTR Q=GetNode();
		Q->info=new_elt;
		Q->next=P->next;
		P->next=Q;
		cout<<"\nSUCCESS!!!\nNew node is successfully inserted after the given node."<<endl<<endl;
	}
}

template<class T>
void CLL<T>::DeleteNode(T elt)
{
	NPTR P=SearchNode(elt);
	if (P==NULL)
	{
		cout<<"\nERROR!!!\nNode that you want to delete is not found!"<<endl<<endl;
	}
	else
	{
		if (P->next==P)			//If there is only one node (i.e. P=Head).
		{
			Head=NULL;
		}
		else
		{
			if (P==Head)
				Head=Head->next;
			NPTR Q=Head;
			while (Q->next!=P)
				Q=Q->next;
			Q->next=P->next;

		}
		delete P;
		cout<<"\nSUCCESS!!!\nThe node is successfully deleted."<<endl<<endl;
	}
}

template<class T>
void CLL<T>::UpdateNode(T prev_elt, T new_elt)
{
	NPTR P=SearchNode(prev_elt);
	if (P==NULL)
	{
		cout<<"\nERROR!!!\nNode that you want to update is not found."<<endl<<endl;
	}
	else
	{
		P->info=new_elt;
		cout<<"\nSUCCESS!!!\nNode is successfully updated."<<endl<<endl;
	}
}

template<class T>
int CLL<T>::Size()
{
	int count=0;
	if (Head!=NULL)
	{
		for (NPTR P=Head; P->next!=Head; P=P->next, count++);
		++count;
	}
	return count;
}

template<class T>
void CLL<T>::Traverse()
{
	if (Head==NULL)
	{
		cout<<"\nThe Linked list is empty.";
	}
	else
	{
		NPTR P=Head;
		
		do
		{
			cout<<" --> "<<P->info;
			P=P->next;
		}
		while(P!=Head);
		cout<<" --> ";
	}
	cout<<endl<<endl;
}

template<class T>
void CLL<T>::Reverse()
{
	if (Head==NULL)
		cout<<"\nThe Linked list is empty.";
	else
	{
		NPTR P=NULL;
		NPTR Q;
		NPTR R=Head;
		while (Head->next!=R)
		{
			NPTR Q=Head->next;
			Head->next=P;
			P=Head;
			Head=Q;
		}
		Head->next=P;
		R->next=Head;
		cout<<"\nSUCCESS!!! The linked list is successfully reversed.";
	}
	cout<<endl<<endl;
}

int main()
{
	cout<<"********************************** CIRCULAR LINKED LIST ********************************** ";
	CLL<char> CL_list;
	char choice;
	int flag=1;
	char element1, element2;
	while(flag)
	{
		cout<<"\n1. Create";
		cout<<"\n2. Traverse";
		cout<<"\n3. Insert Before";
		cout<<"\n4. Insert After";
		cout<<"\n5. Delete Node";
		cout<<"\n6. Update Node";
		cout<<"\n7. Size";
		cout<<"\n8. Reverse";
		cout<<"\n9. Exit";
		cout<<"\n\nEnter choice : ";
		cin>>choice;
		switch(choice)
		{
			case '1'	:	cout<<"\nEnter first node : ";
							cin>>element1;
							CL_list.Create(element1);
							break;
			case '2'	:	cout<<endl;
							CL_list.Traverse();
							break;
			case '3'	:	cout<<"\nEnter the node you want to insert : ";
							cin>>element1;
							cout<<"\nEnter the node before which you want to insert your node : ";
							cin>>element2;
							CL_list.InsertBefore(element1,element2);
							break;
			case '4'	:	cout<<"\nEnter the node you want to insert : ";
							cin>>element1;
							cout<<"\nEnter the node after which you want to insert your node : ";
							cin>>element2;
							CL_list.InsertAfter(element1,element2);
							break;
			case '5'	:	cout<<"\nEnter the node that you want to delete : ";
							cin>>element1;
							CL_list.DeleteNode(element1);
							break;
			case '6'	:	cout<<"\nEnter the node you want to update : ";
							cin>>element1;
							cout<<"\nEnter the new node : ";
							cin>>element2;
							CL_list.UpdateNode(element1,element2);
							break;
			case '7'	:	cout<<"\nThe size of the linked list is : "<<CL_list.Size()<<endl<<endl;
							break;
			case '8'	:	CL_list.Reverse();
							break;
			case '9'	:	flag=0;
							break;
			default		:	cout<<"\n\nERROR!!! You entered a wrong choice."<<endl<<endl;
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}
