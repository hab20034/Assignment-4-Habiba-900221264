#include <vector>
#include "Assignment4.h"

void linkedlist::insertnode(int elements, int count){
	Node* newnode= new Node;
	newnode->data=elements;
	newnode->counter=count;
	if(length==0){
		head=tail=newnode;
		newnode->next=NULL;
		}
	else{
		tail->next=newnode;
		newnode->next=NULL;
		tail=newnode;
		}
	length++;
}

void linkedlist::display(){
	Node* temp= head;
	if(head==NULL){
		cout << "Empty" << endl;
		return;
	}
	
	while(temp!=NULL){
		cout << temp->data << " " <<"occurs" << " " << temp->counter << " " << "times" << endl;
		temp=temp->next;
	}
}

void insertAfter(int firstVal, int secondVal, vector<int>& v1){
	for(int i=0; i<v1.size(); i++)
	{
		if(v1[i]==firstVal)
			v1.insert(v1.begin()+ (i+1), secondVal); //referenced from geeksforgeeks
	}
	
}
void createlist(linkedlist& L1,vector<int>& v1){
	int temp[v1.size()]; 
	int x=0;
	for(int i=0; i<v1.size(); i++){
		for(int k=0; k<x; k++)
		{
			if(v1[i]==temp[k]){
				i++; 
		}}
		int count=0;
		for (int j=0; j<v1.size(); j++){
			if (v1[i]==v1[j])
				count++;
		}
		if(count==1){
			L1.insertnode(v1[i], count);
		}
		else if(count>=2)
		{
			L1.insertnode(v1[i], count);
			temp[x]=v1[i];
			x++;
			}		
	}
}

void linkedlist::sumNodes(int& sumnodes)
{
	Node* temp=head;
	while(temp!=NULL){
		sumnodes+=temp->data;
		temp=temp->next;
	}
}


int main (){
	int n, first, second;
	vector<int> v(n);
	cout << "How many numbers would you like to insert" << endl;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}
	cout << "Enter first value and second value" << endl;
	cin >> first >> second;
	insertAfter(first, second, v);
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	linkedlist list;
	createlist(list, v);
	list.display();
	int sum=0;
	list.sumNodes(sum);
	cout << sum << endl;
}
