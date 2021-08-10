#include<iostream>
using namespace std;

class BST {
public:
	typedef struct Node;
	struct infor {
		string id, name;
		int status;
		struct bir {
			int d, m, y;
		}dob;
	};
	
	BST();
	Node* createNode(infor);
	void insertNode(infor);
	Node* SearchID(string);
	void deleteNode(string);
	void ListGraduated(BST&);
	void printTree(ostream&);
	void printFile(ostream&);
	Node* getRoot();
	~BST() {};

	friend class SchoolClasses;
private:
	struct Node {
		infor data;
		Node* left, * right;

	};
	int n;
	Node* root;

	void insert(Node*&, infor);
	void printTree(Node*, ostream&);
	void printFile(Node*, ostream&);
	Node* SearchID(Node*, string);
	Node* minNode(Node*);
	Node* deleteNode(Node*, string);
	void ListGraduated(Node*, BST&);
	void printInforNode(Node*);
};