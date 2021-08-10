#include"BST.h"

BST::BST() {
	root = nullptr;
	n = 0;
}

BST::Node* BST::createNode(infor data) {
	Node* node = new Node;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}
void BST::insert(Node*& root, infor data) {
	if (!root) {
		root = createNode(data);
		n++;
		return;
	}
	if (root->data.id == data.id)	return;
	if (root->data.id > data.id)	insert(root->left, data);
	if (root->data.id < data.id)	insert(root->right, data);
}
void BST::insertNode(infor data) {
	insert(root, data);
}

BST::Node* BST::SearchID(Node* root, string id) {
	if (root == nullptr || root->data.id == id)
		return root;
	if (root->data.id > id)	return SearchID(root->left, id);
	if (root->data.id < id)	return SearchID(root->right, id);
}
BST::Node* BST::SearchID(string id) {
	return SearchID(root, id);
}

BST::Node* BST::minNode(Node* root) {
	while (root && root->left) {
		root = root->left;
	}
	return root;
}

BST::Node* BST::deleteNode(Node* root, string id) {
	if (!root)	return root;

	if (root->data.id > id)
		root->left = deleteNode(root->left, id);
	else if (root->data.id < id)
		root->right = deleteNode(root->right, id);
	else {
		if (!root->left) {
			Node* tmp = root->right;
			delete root;
			n--;
			return tmp;
		}
		else if (!root->right) {
			Node* tmp = root->left;
			delete root;
			n--;
			return tmp;
		}

		Node* tmp = minNode(root->right);

		root->data = tmp->data;
		root->right = deleteNode(root->right, tmp->data.id);
	}
	return root;
}
void BST::deleteNode(string id) {
	deleteNode(root, id);
}

void BST::ListGraduated(Node* root, BST& res) {
	if (!root)
		return;
	if (root->data.status)
		res.insertNode(root->data);
	if (root->left)		ListGraduated(root->left, res);
	if (root->right)	ListGraduated(root->right, res);
}
void BST::ListGraduated(BST& res) {
	ListGraduated(root, res);
}

void BST::printInforNode(Node* p) {
	cout << "ID: " << p->data.id << endl;
	cout << "Name: " << p->data.name << endl;
	cout << "DoB: " << p->data.dob.d << "/" << p->data.dob.m << "/" << p->data.dob.y << endl;
	cout << "Status: ";
	if (p->data.status == 1)	cout << "graduated\n";
	else cout << "undergrad\n";
}

void BST::printTree(Node* root, ostream&out) {
	if (!root)
		return;
	if (root->left)		printTree(root->left, out);
	out << root->data.id << "\t" << root->data.name << "\t\t" << root->data.dob.d << "/" << root->data.dob.m << "/" << root->data.dob.y << "\t  " << root->data.status << endl;
	if (root->right)	printTree(root->right, out);
}
void BST::printTree(ostream& out) {
	printTree(root, out);
}

void BST::printFile(Node* root, ostream& out) {
	if (!root)
		return;
	if (root->left)		printFile(root->left, out);
	out << root->data.id << "\n" << root->data.name << "\n" << root->data.dob.d << "/" << root->data.dob.m << "/" << root->data.dob.y << "\n" << root->data.status << endl;
	if (root->right)	printFile(root->right, out);
}
void BST::printFile(ostream& out) {
	printFile(root, out);
}

BST::Node* BST::getRoot() {
	return root;
}