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

node* kreverse(node* head, int k,int times){
	//base case
	if(head==NULL or times==0){
		return head;
	}

	//rec case
	node* prev = NULL;
	node* curr = head;
	node* nxt;

	int count=0;
	while(count<k){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		count++;
	}
	//now curr is at I*k+1 th node
	times--;
	head->next = kreverse(curr,k,times);
	

	return prev;
}


int main() {
	int n;
	cin>>n;
	int k;
	cin>>k;

	int d;
	node* head=NULL;
	node* temp=NULL;
	
	for(int i=1;i<=n;i++){
		cin>>d;
		node* newNode= new node(d);
		if(i==1){
			head=newNode;
			temp=newNode;
		}
		else{
			temp->next=newNode;
			temp=newNode;
		}
	}

	int times = n/k;
	head = kreverse(head,k,times);
	//Priting
	temp= head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	return 0;
}