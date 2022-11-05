////////////////////
// inne . cpp
////////////////////

#include <iostream>
#include <random>
#include <locale>
#include <string>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;

void setup() {
	setlocale(LC_CTYPE, "Polish");
	cout.precision(2);
	cout << fixed;
}

void colors(char c) {
	switch (c) {
	case 'x':
		cout << RESET;
		break;
	case 'r':
		cout << RED;
		break;
	case 'g':
		cout << GREEN;
		break;
	case 'y':
		cout << YELLOW;
		break;
	case 'b':
		cout << BLUE;
		break;
	case 'm':
		cout << MAGENTA;
		break;
	case 'c':
		cout << CYAN;
		break;
	default:
		break;
	}
}

