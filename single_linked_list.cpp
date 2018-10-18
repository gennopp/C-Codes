#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node_{
	int data;
	struct node_ *next;
}node; 

typedef node *mylist;
mylist head = NULL;

void add_(int n){
	mylist new_node = new node;
	new_node->data = n;
	if(head == NULL){
		new_node->next = NULL;
	}
	else {
		new_node->next = head;
	}
	head = new_node;
}

void remove_(int n){
	mylist ptr = head; 
	if(ptr->data == n){
		head = ptr->next;
		delete ptr;
	}
	else{
		mylist ptr1;
		while(ptr->data != n){
			ptr1 = ptr;
			ptr = ptr->next;
		}
		ptr1->next = ptr->next;
		delete ptr;
	}
}

void search_(int n){
	mylist ptr = head; 
	bool flag = false;
	while(ptr != NULL){
		if(ptr->data == n){
			flag = true;
			break;
		}
		ptr = ptr->next;
	}
	if(flag == true)
		cout<<"\nFOUND";
	else
		cout<<"\nNot Found";
}

void print_(){
	mylist ptr = head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
}

void remove_pos(int n){
	mylist ptr = head;
	if(head == NULL)
		return;
	if(n==1){
		head = ptr->next;
		delete ptr;
	}
	else{
		for (int i=0; ptr!=NULL && i<n-1; i++) 
        	ptr = ptr->next; 
		mylist next = ptr->next->next; 
		delete ptr->next;
		ptr->next = next;
	}
}

void find_mid(){
	int count = 0;
	mylist mid = head;
	mylist ptr = head;
	while(ptr != NULL){
		if(count & 1)
			mid = mid->next;

		++count;
		ptr = ptr->next;
	}
	cout<<mid->data<<endl;
}


int main(){
	int n, key;
	while(1){
		cout<<"\n1. Add\n2. Remove\n3. Search\n4. Display List\n5. Remove by Position\n6. Middle Element";
		cout<<"\nChoose: ";cin>>key;
		switch(key){
			case 1: 
				cout<<"\nEnter the element: ";
				cin>>n;
				add_(n);
				break;
			case 2:
				cout<<"\nEnter the element to remove: ";cin>>n;
				remove_(n);
				break;
			case 3:
				cout<<"\nEnter the element to search: ";cin>>n;
				search_(n);
				break;
			case 4:
				cout<<"\nElements are: "<<endl;
				print_();
				break;
			case 5:
				cout<<"\nEnter the position to remove: ";cin>>n;
				remove_pos(n);
				break;
			case 6:
				cout<<"\nThe middle element is: ";
				find_mid();
				break;
			default:
				exit(0);
		}

	}
}