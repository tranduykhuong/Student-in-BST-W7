#include"programFrame.h"

void title() 
{
	system("cls");
	cout << "\t==================/***\\==================\n"
		<< "\t=\tSTUDENT MANAGEMENT PROGRAM\t=\n"
		<< "\t==================\\***/==================\n\n";
}

void MenuFile()
{
	title();
	cout << "\tThe options:\n"
		<< "\t1. Load data from Demo file of program\n"
		<< "\t2. Load data from your file\n"
		<< "\t3. Quit\n";
}

void MenuProcess()
{
	title();
	cout << "\tThe options:\n"
		<< "\t0. Print the student List\n"
		<< "\t1. Create new student info and insert this item\n"
		<< "\t2. Find a student by ID / update of the student info\n"
		<< "\t3. List all students in lexicographic order of their names\n"
		<< "\t4. Delete a student given by its code\n"
		<< "\t5. List/Delete/Save all graduated students\n"
		<< "\t6. Save list to file\n"
		<< "\t7. Load an other file\n"
		<< "\t8. Exit\n";
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

void inputFilename(int ans, string& file)
{
	if (ans == 1)
		file = "student.txt";
	else {
		cout << "Enter file's name (*.txt): ";
		cin.ignore();
		getline(cin, file);
		if (file[file.length() - 4] != '.')
			file += ".txt";
	}
}