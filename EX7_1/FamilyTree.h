#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FamilyTree {
	struct Node {
		string name;
		Node* left, * right;
	};
	Node* root;

	Node* createNode(string);
	Node* insertNode(Node*, string);
	void PreOrder(Node*, ostream&);
	void InOrder(Node*, ostream&);
	void PostOrder(Node*, ostream&);
	void SearchName(Node*, string, Node**);
public:
	FamilyTree();
	void insertNode(string);
	void PreOrder(ostream&);
	void InOrder(ostream&);
	void PostOrder(ostream&);

	void ReadFile(string);
	void insertFamily(string, string, string);
};

void inputSelect(int& ans, int beg, int end);
void Menu();
void SelectPrint(string& fn);