#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "List.h"
using std::string;
using std::cout;

class Menu {
public:
	void run();
	int val_menu(int numOptions);
private:
	List list;
	std::ifstream infile;
	std::ofstream outfile;
	void display_main();
	void display_sub();
	void to_file(string file);
	void make_list(string file);
};