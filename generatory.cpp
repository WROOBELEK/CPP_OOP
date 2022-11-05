////////////////////
// inne . cpp
////////////////////

#include <iostream>
#include <random>
#include <locale>
#include <string>

using namespace std;

size_t GeneratorLiczba(size_t min, size_t max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<size_t> uid(min, max);
	return uid(mt);
}

string GeneratorLogin(string name, string surname) {
	string login = surname;
	login.insert(login.size(), name, 0, 1);
	transform(login.begin(), login.end(), login.begin(),[](unsigned char c) { 
		return tolower(c); 
	});
	return login;
}

string GeneratorEmail(string name, string surname) {
	string email = "";
	string login = surname;
	login.insert(login.size(), name, 0, 1);
	transform(login.begin(), login.end(), login.begin(), [](unsigned char c) {
		return tolower(c);
	});
	email = login + "@distcenter.pl";
	return email;
}

string GeneratorPesel(unsigned short dzien, unsigned short miesiac, unsigned short rok, bool plec) {
	string pesel = "";
	unsigned short num = 0;
	unsigned short sum = 0;
	unsigned short temp = 0;
	//naprawa stoi out of range
	string temp_fix, p5, p6;
	if (dzien < 10) {
		temp_fix = "0" + to_string(dzien);
	}
	string p1 = to_string(rok); p1.erase(0, 2); p1.erase(1, 1);
	string p2 = to_string(rok); p2.erase(0, 3);
	string p3 = to_string(miesiac + 20);  p3.erase(1, 1);
	string p4 = to_string(miesiac + 20);  p4.erase(0, 1);
	if (dzien < 10) {
		p5 = temp_fix;  p5.erase(1, 1);
		p6 = temp_fix;  p6.erase(0, 1);
	}
	else {
		p5 = to_string(dzien);  p5.erase(1, 1);
		p6 = to_string(dzien);  p6.erase(0, 1);
	}
	string p7 = to_string(GeneratorLiczba(0, 9));
	string p8 = to_string(GeneratorLiczba(0, 9));
	string p9 = to_string(GeneratorLiczba(0, 9));
	string p10 = to_string(GeneratorLiczba(0, 9));
	//cout << dzien << "xxx " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << "a " << p6 << "b " << p7 << " " << p8 << " " << p9 << " " << p10 << endl << endl;
	while (true) {
		if ((plec == true && stoi(p10) % 2 == 1) || (plec == false && stoi(p10) % 2 == 0)) {
			break;
		}
		else {
			p10 = to_string(GeneratorLiczba(0, 9));
		}
	}
	num = stoi(p1) * 0;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p2) * 3;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p3) * 7;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p4) * 9;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p5) * 1;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p6) * 3;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p7) * 7;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p8) * 9;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p9) * 1;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	num = stoi(p10) * 3;
	if (num > 9) {
		num = num % 10;
	}
	sum = sum + num;

	if (sum > 9) {
		sum = sum % 10;
	}

	string p11 = to_string(10 - sum);

	pesel = pesel + p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10 + p11;

	return pesel;
}