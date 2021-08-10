#include"FamilyTree.h"

int main()
{
	FamilyTree tree;
	int ans;
	tree.ReadFile("input.txt");
	while (1) {
		Menu();			inputSelect(ans, 1, 5);
		if (ans == 5)	return 0;
		string fn;		SelectPrint(fn);
		ofstream fout(fn);
		if (!fout)
			cout << "Failed to open file!\n";
		else {
			switch (ans) {
			case 1:
				tree.PreOrder(fout);	break;
			case 2:
				tree.InOrder(fout);		break;
			case 3:
				tree.PostOrder(fout);	break;
			case 4:
				fout << "PreOrder:\n";	tree.PreOrder(fout);
				fout << "\nInOrder:\n";	tree.InOrder(fout);
				fout << "\nPostOrder:\n";	tree.PostOrder(fout);
				break;
			}
			cout << "Print successfully\n";
		}
		system("pause");
	}
}