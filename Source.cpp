#include "List.h"
#include "Node.h"
#include <iostream>
using namespace std;


	
void menu() {
	cout << "1 - Add to head\t2 - Add to tail\n";
	cout << "3 - Delete from tail\t4 - delete from head\n";
	cout << "5 - Delete all\t6 - Show\n";
	cout << "7 - Set at(position)\t8 - Del from(position)\n";
	cout << "9 - Search el\t10 - Change elements\n";
}

int main() {
	srand(time(0));
	List<int> list;


	for (int i = 0; i < 5; i++) {
		list.addToTail(rand() % 10 + 1);
	}
	int choice;
	int addToHeadEl;
	int addToTailEl;

	int addAtPos;
	int addPosEl;

	int delFromPos;

	int searchEl;
	int searchPos;

	int searchForChangeEl;
	int changeEl;
	
	do {
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter element: ";
			cin >> addToHeadEl;
			list.addToHead(addToHeadEl);
			break;
		case 2:
			cout << "Enter element: ";
			cin >> addToTailEl;
			list.addToTail(addToTailEl);
			break;
		case 3:
			list.removeFromTail();
			break;
		case 4:
			list.removeFromHead();
			break;
		case 5:
			list.removeAll();
			break;
		case 6:
			list.show();
			cout << "\n";
			break;
		case 7:
			cout << "Enter position: ";
			cin >> addAtPos;
			cout << "Enter value: ";
			cin >> addPosEl;
			list.addAt(addPosEl, addAtPos);

			break;
		case 8:
			cout << "Enter position: ";
			cin >> delFromPos;
			list.delAt(delFromPos);

			break;
		case 9:
			
			cout << "Enter element: ";
			cin >> searchEl;
			searchPos = list.getPositionElement(searchEl);
			if (searchPos != -1) {
				cout << "Element [" << searchEl << "] placed on: " << searchPos + 1 << " position\n";
			}
			
			break;
		case 10:
			cout << "Enter searched element: ";
			cin >> searchForChangeEl;
			cout << "Enter changed element: ";
			cin >> changeEl;
			list.changeValueOfElements(searchForChangeEl, changeEl);
			break;
		default:
			break;
		}
	} while (choice != 0);
	
	
	//list.show();

	//int searchedEl;
	//cout << "enter el: ";
	//cin >> searchedEl;
	//int position = list.getPositionElement(searchedEl);
	//if (position != 1) {
	//	cout << "Element [" << searchedEl << "] placed on " << position + 1 << " position\n";

	//}
	//else {
	//	cout << "No matches\n";
	//}

	return 0;

}