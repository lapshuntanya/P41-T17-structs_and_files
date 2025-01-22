#pragma once
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

struct Card
{
	char name[30] = "undefined";	//ПІ клієнта
	unsigned long number = 0;		//Номер картки
	double cash = 0;				//Сума коштів на картці

	void createCard() {
		cout << "Input your name: ";
		cin.getline(name, 30);
		number = rand() * 1'000'000 + rand();
		cash = 1'000;
	}
	void showCard() {
		cout << "+++++++++++++++++++++++++++++\n";
		cout << "|\tClient: " << name << endl;
		cout << "|\tCard:   " << number << endl;
		cout << "|\tCash:   " << cash << " UAH" << endl;
		cout << "+++++++++++++++++++++++++++++\n";
	}

	void saveToBinFile(FILE* file) {
		int lengthName = strlen(name) + 1;
		fwrite(&lengthName, sizeof(int), 1, file);//save name
		fwrite(name, sizeof(char), lengthName, file);

		fwrite(&number, sizeof(unsigned long), 1, file);//save number
		fwrite(&cash, sizeof(double), 1, file);//save cash
	}
	
	void loadFromBinFile(FILE* file) {
		int lengthName = 0;
		fread(&lengthName, sizeof(int), 1, file);//load name
		fread(name, sizeof(char), lengthName, file);

		fread(&number, sizeof(unsigned long), 1, file);//load number
		fread(&cash, sizeof(double), 1, file);//load cash
	}
};