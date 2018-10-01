#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct node
{
	char employee_name[50],employee_id[20];
	int salary;
	
	struct node *prev,*next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start,char employee_name[],char employee_id[],int salary );
struct node *addatbeg(struct node *start,char employee_name[],char employee_id[],int salary);
struct node *delatend(struct node *start,char employee_name[]);
struct node *addatend(struct node *start,char employee_name[],char employee_id[],int salary);
int main()
{
	char employee_name[50],employee_id[20];
	int salary;
    int choice,n,i;
  
  struct node *start=NULL;
  
  while(1)
  {
  	cout<<"\n 1.Press 1 to create a list";
  	cout<<"\n 2.Press 2 to add at the begining of the list";
  	cout<<"\n 3.Press 3 to delete the employees from the list";
  	cout<<"\n 4.Press 4 to display the information of the employees";
  	cout<<"\n 5.Press 5 to quit";
  	
  	cout<<"\n Enter your choice";
  	cin>>choice;
  	
  	switch(choice)
  	{
  		case 1:
  			start=create_list(start);
  			break;
  		
		case 2:
		    cout<<"\n Enter the number of employees you want to insert at the begining";
			cin>>n;
			
			cout<<"\n Enter the information of the employees";
			for(i=0;i<n;i++)
			{
				cout<<"\n Enter the name of the employee :";
				gets(employee_name);
				gets(employee_name);
				fflush(stdin);
				
				cout<<"\n Enter the id of the employee :";
				gets(employee_id);
			//	gets(employee_id);
				fflush(stdin);	
				
				cout<<"\n Enter the salary of the employee :Rs.";
				cin>>salary;
				start=addatbeg(start,employee_name,employee_id,salary);
			  }  	
			break;
			
		case 3:
			cout<<"\n Enter the number of employees you want to delete from the end";
			cin>>n;
			
			for(i=0;i<n;i++)
			{
			cout<<"\n Enter the name of the employee:";
			gets(employee_name);
			gets(employee_name);
		//	fflush(stdin);
			delatend(start,employee_name);
		 }
			break;
		
		case 4:
		display(start);
		break;
		
		case 5:
		exit(1);		  
	  	}/*end of switch */
	  
	  }	/*end of while*/
}/*end of main*/

struct node *create_list(struct node *start)
{
	char employee_name[50],employee_id[20];
	int salary;
	int i,n;
	cout<<"\n Enter the number of employees :";
	cin>>n;
	
	start=NULL;
	
	if(n==0)
		return start;
	
	cout<<"\n Enter the name of the employee :";
		gets(employee_name);
		gets(employee_name);
		fflush(stdin);
				
	cout<<"\n Enter the id of the employee :";
		gets(employee_id);
	//	gets(employee_id);
		fflush(stdin);
				
	cout<<"\n Enter the salary of the employee :Rs.";
	cin>>salary;
	
	start=addtoempty(start,employee_name,employee_id,salary);
	
	for(i=2;i<=n;i++)
	{
		cout<<"\n Enter the name of the employee :";
		gets(employee_name);
		gets(employee_name);
		fflush(stdin);
				
		cout<<"\n Enter the id of the employee :";
		gets(employee_id);
	//	gets(employee_id);
		fflush(stdin);
				
		cout<<"\n Enter the salary of the employee :Rs.";
		cin>>salary;
		
		start=addatend(start,employee_name,employee_id,salary);
		}	
		
		return start;
		
} /* End of create list*/

struct node *addtoempty(struct node *start,char employee_name[],char employee_id[],int salary)
{
	struct node *tmp;
	
	tmp=(struct node *)malloc(sizeof(struct node));
	strcpy(tmp->employee_name,employee_name);
	strcpy(tmp->employee_id,employee_id);
	tmp->salary=salary;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	
	return start;
} /* End of add to empty list */

struct node *addatbeg(struct node *start,char employee_name[],char employee_id[],int salary)
{
	struct node *tmp;
	
	tmp=(struct node *)malloc(sizeof(struct node));
	
	strcpy(tmp->employee_name,employee_name);
	strcpy(tmp->employee_id,employee_id);
	tmp->salary=salary;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	
	return start;
} /* End of add at begining */

struct node *addatend(struct node *start,char employee_name[],char employee_id[],int salary)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	strcpy(tmp->employee_name,employee_name);
	strcpy(tmp->employee_id,employee_id);
	tmp->salary=salary;
	p=start;
	
	while(p->next!=NULL)
		p=p->next;
	
	tmp->next=NULL;
	p->next=tmp;
	tmp->prev=p;
	
	return start;	
}

struct node *delatend(struct node *start,char employee_name[])
{
	
	struct node *tmp;
	
	if(start==NULL)
	{
		cout<<"\n List is empty";
		return start;
	}
	
	if(start->next==NULL) /* Deletion of only node */
	 	if(stricmp(start->employee_name,employee_name)==0)
		{
		  tmp=start;
		  start=NULL;
		  free(tmp);
		  return start;
		}
		
		else
		{
			cout<<"\n Employee not found";
			return start;
		}
		
	if(stricmp(start->employee_name,employee_name)==0) /* Deletion of 1st node*/
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		
		return start;
		
		}	
		
	tmp=start->next; /*Deletion in b/w */
	while(tmp->next!=NULL)
	{
		if(stricmp(tmp->employee_name,employee_name)==0)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			
			return start;
		}
		tmp=tmp->next;
		}	
	if(stricmp(start->employee_name,employee_name)==0) /* Deletion of last node */
	{
		
		tmp->prev->next=NULL;
		free(tmp);
		
		return start;
		}	
		
	cout<<"\n Employee not found";
	
	return start;	
 } /*end of delete*/
 
 void display(struct node *start)
{
	struct node *p;
	if(start == NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	p=start;
	cout<<"\n Employees list is  :\n";
	while(p!=NULL)
	{
		cout<<"\n Name of the employee is:"<<p->employee_name;
		cout<<"\n ID of the employee is:"<<p->employee_id;
		cout<<"\n Salary of the employee is :Rs."<<p->salary<<endl;
		p=p->next;
	}
	cout<"\n";
}
