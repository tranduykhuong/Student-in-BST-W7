#include"FamilyTree.h"

FamilyTree::FamilyTree()
{
	root = nullptr;
}

FamilyTree::Node* FamilyTree::createNode(string name)
{
	Node* newnode = new Node;
	newnode->name = name;
	newnode->left = newnode->right = nullptr;
	return newnode;
}

FamilyTree::Node* FamilyTree::insertNode(Node* head, string name)
{
	if (head == nullptr)
		return createNode(name);
	if (name < head->name)
		head->left = insertNode(head->left, name);
	if (name > head->name)
		head->right = insertNode(head->right, name);
	return head;
}
void FamilyTree::insertNode(string name)
{
	root = insertNode(root, name);
}

void FamilyTree::PreOrder(Node* p, ostream& out)
{
	if (p == nullptr)
		return;
	out << p->name << " ";
	PreOrder(p->left, out);
	PreOrder(p->right, out);
}
void FamilyTree::PreOrder(ostream& out) {
	PreOrder(root, out);
}

void FamilyTree::InOrder(Node* p, ostream& out)
{
	if (p == nullptr)
		return;
	InOrder(p->left, out);
	out << p->name << " ";
	InOrder(p->right, out);
}
void FamilyTree::InOrder(ostream& out) {
	InOrder(root, out);
}

void FamilyTree::PostOrder(Node* p, ostream& out)
{
	if (p == nullptr)
		return;
	PostOrder(p->left, out);
	PostOrder(p->right, out);
	out << p->name << " ";
}
void FamilyTree::PostOrder(ostream& out) {
	PostOrder(root, out);
}

void FamilyTree::SearchName(Node* p, string name, Node** res)
{
	if (p == nullptr || p->name == name) {
		*res = p;
		return;
	}
	if (p->left)	SearchName(p->left, name, res);
	if (p->right)	SearchName(p->right, name, res);
}

void FamilyTree::insertFamily(string parent, string child1, string child2)
{
	if (root == nullptr) {
		root = createNode(parent);
		root->left = createNode(child1);
		if (child2 != "0");
			root->right = createNode(child2);
		return;
	}
	Node* p;
	SearchName(root, parent, &p);
	if (p) {
		p->left = createNode(child1);
		if (child2 != "0");
			p->right = createNode(child2);
		return;
	}
}

void FamilyTree::ReadFile(string filename)
{
	ifstream fin(filename);
	if (!fin)	return;
	int n;	fin >> n;
	string pr, ch1, ch2;	
	char c;
	for (int i = 0; i < n; i++) {
		fin.get(); fin.get();
		fin >> pr;
		fin.get(); fin.get();
		fin >> ch1;
		fin >> ch2;
		if (ch2[0] != ')')
			ch2 = ch2.substr(0, ch2.length() - 2);
		else ch2 = "0";
		insertFamily(pr, ch1, ch2);
	}
	fin.close();
}

void inputSelect(int& ans, int beg, int end)
{
	cout << "\tYour choice: ";
	cin >> ans;
	if (ans<beg || ans>end) {
		cout << "Enter error! Please enter again!\n";
		return inputSelect(ans, beg, end);
	}
}

void Menu()
{
	system("cls");
	cout << "\tA FAMILY TREE\n"
		<< "\t-----/*\\-----\n";
	cout << "The program has read the \"input.txt\" file of the topic\n\n";
	cout << "\tThe options:\n"
		<< "\t1. PreOrder (NLR)\n"
		<< "\t2. InOrder (LNR)\n"
		<< "\t3. PostOrder (LRN)\n"
		<< "\t4. All cases above\n"
		<< "\t5. Quit\n";
}

void SelectPrint(string& fn)
{
	system("cls");
	cout << "\tA FAMILY TREE\n"
		<< "\t-----/*\\-----\n";
	cout << "Enter your file's name to print to file: ";
	cin.ignore();
	getline(cin, fn);
}