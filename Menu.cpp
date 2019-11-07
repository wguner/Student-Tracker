#include "Menu.h"

void Menu::display_main() {
	cout << "\n1. Import course list\n2. Load master list\n 3. Store master list\n"
		"4. Mark absences\n 5.BONUS: Edit absences [Not Working]\n 6. Generate report\n 7.Exit\n";
}

void Menu::display_sub() {
	cout << "\n1.Generate report for all students\n 2.Generate report for students with absences that match or exceed." << endl;
}

int Menu::val_menu(int numOptions) { //template menu code from previous assignments. so i dont have to write this every time. 
	string selection = "0";
	while ((!isdigit(selection.at(0))) || stoi(selection) < 1 || stoi(selection) > numOptions) {
		cout << "\nPlease enter a number from 1 to " << numOptions << '\n';
		cin >> selection;
		if ((!isdigit(selection.at(0))) || stoi(selection) < 1 || stoi(selection) > numOptions) {
			cout << "\n Invalid Entry.";
		}
	}
	return stoi(selection);
}

void Menu::to_file(string file) {
	infile.open(file);
	if (infile.good()) {
		list.load_list(infile);
	}
	else {
		cout << "Could not find the file" << endl;
	}
}

void Menu::make_list(string file) {
	outfile.open(file);
	list.store_list(outfile);
}

void Menu::run() {
	int option = 0, option_sub = 0;
	cout << "Attendance Tracker\n Output will be saved to list.csv" << endl;
	make_list("classList.csv");
	while (option <= 7) {
		display_main();
		option = val_menu(7);
		switch (option) {
		case 1:
			make_list("classList.csv");
			break;
		case 2:
			make_list("list.csv");
			break;
		case 3:
			to_file("list.csv");
			break;
		case 4:
			list.set_absences();
			break;
		case 5:
			cout << "Nothing here yet.\n" << endl; //bonus
			break;
		case 6:
			display_sub();
			option_sub = val_menu(2);
			if (option_sub == 1) {
				list.mostRecentAbsence();
			}
			else {
				cout << "Display students with absences over: ";
				option_sub = val_menu(180);
				list.allAbsences(option_sub);
			}
			break;
		case 7:
			to_file("list.csv");
			break;
		}
	}
}