#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;

	node(int d){
		data=d;
		next=NULL;
	}
};

node* bubble_sort(node* head,int n){
	//base case
	if(n==1){
		return head;
	}

	//rec case
	node* ptr = head;
	node* ptr2 = ptr->next;
	node* temp = NULL;
	int count=0;
	while(ptr2!=NULL and count < n-1){
		if(ptr->data > ptr2->data){
			ptr->next=ptr2->next;
			ptr2->next=ptr;
			if(count==0){
				head=ptr2;
				temp=ptr2;
			}
			else{
				temp->next=ptr2;
				temp=ptr2;
			}
			ptr2=ptr->next;
		}

		else{
			temp=ptr;
			ptr=ptr->next;
			ptr2=ptr2->next;
		}

		count++;
	}
	return bubble_sort(head,n-1); 
}

int main() {
	int n;
	cin>>n;
	int d;
	node* head=NULL;
	node* temp=NULL;
	for(int i=1;i<=n;i++){
		cin>>d;
		node* newnode = new node(d);
		if(i==1){
			head=newnode;
			temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
	}

	head=bubble_sort(head,n);

	//Printing
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return 0;
}