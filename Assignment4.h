#include <iostream>
using namespace std;

class linkedlist{
		struct Node{
			int data;
			Node* next;
			int counter;
		};
		int length;
		
	public:
		void insertnode(int, int);
		void display();
		void sumNodes(int&);
		Node node;
		Node* head;
		Node* tail;
		linkedlist() {head=tail=NULL; length=0;};
		//void deletenode(int);		
};
