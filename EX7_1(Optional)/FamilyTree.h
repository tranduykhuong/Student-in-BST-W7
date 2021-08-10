#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define MAX 15

class FamilyTree {
	struct Node {
		string name;
		int n;
		Node* c[MAX]{ nullptr };
	};
	Node* root;

	Node* createNode(string);
	void PreOrder(Node*, ostream&);
	void InOrder(Node*, ostream&);
	void PostOrder(Node*, ostream&);
	void SearchName(Node*, string, Node**);
public:
	FamilyTree();
	void PreOrder(ostream&);
	void InOrder(ostream&);
	void PostOrder(ostream&);

	void ReadFile(string);
	void insertFamily(string, string [], int);
	~FamilyTree() {};
};

void inputSelect(int& ans, int beg, int end);
void Menu();
void SelectPrint(string& fn);