#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Tested Using Sequence: CAUGGCTAUAAAUGAAUAG

string codeSequence;
int codeLength;
bool searchResult = false;


void mRNA() {
	cout << "Insert code sequence:" << endl;
	cin >> codeSequence;
	cout << "The code entered is: " << codeSequence << endl;
	codeLength = codeSequence.length();
	cout << "The length of the string is " << codeLength << endl;
}

void startCodon() {
	cout << "Possible 'start' sequences will be found: " << endl;
	string::size_type AUG = -1;
	do {
		AUG = codeSequence.find("AUG", AUG + 1);
		if (AUG != std::string::npos) {
			cout << "at position: " << AUG << endl;
			searchResult = true;	
		}
		else
			searchResult = false;
		} while (searchResult == true);
}

void stopCodonUAA() {
	cout << "Possible 'UAA STOP' sequences will be found: " << endl;
	string::size_type UAA = -1;
	int count = 0;
	do {
		UAA = codeSequence.find("UAA", UAA + 1);
		if (UAA != std::string::npos) {
			cout << "at position: " << UAA << endl;
			count++;
			searchResult = true;
		}
		else
			searchResult = false;
		} while (searchResult == true);
	if (count == 0)
		cout << "None Found... \n";
}

void stopCodonUAG() {
	cout << "Possible 'UAG STOP' sequences will be found: " << endl;
	string::size_type UAG = -1;
	int count = 0;
	do {
		UAG = codeSequence.find("UAG", UAG + 1);
		if (UAG != std::string::npos) {
			cout << "at position: " << UAG << endl;
			count++;
			searchResult = true;
		}
		else
			searchResult = false;
	} while (searchResult == true);
	if (count == 0)
		cout << "None Found... \n";
}

void stopCodonUGA() {
	cout << "Possible 'UGA STOP' sequences will be found: " << endl;
	string::size_type UGA = -1;
	int count = 0;
	do {
		UGA = codeSequence.find("UGA", UGA + 1);
		if (UGA != std::string::npos) {
			cout << "at position: " << UGA << endl;
			count++;
			searchResult = true;
		}
		else
			searchResult = false;
	} while (searchResult == true);
	if (count == 0)
		cout << "None Found... \n";
}

void intronRemoval() {

}

void rnaSequence() {
	string::size_type AUG = -1;
	string::size_type UAA = -1;
	string::size_type UAG = -1;
	string::size_type UGA = -1;
	int countStart = 0;
	int countStopUAA = 0;
	int countStopUAG = 0;
	int countStopUGA = 0;
	int countStop = 0;
	int countStopCurrent;
	int positions;
	int positionDifference;

	do {
		AUG = codeSequence.find("AUG", AUG + 1);
		if (AUG != std::string::npos) {
			countStart++;
			searchResult = true;
		}
		else
			searchResult = false;
	} while (searchResult == true);
	AUG = -1;
	int *startArray = new int[countStart];
	for (int i = 0; i < countStart; i++) {
		AUG = codeSequence.find("AUG", AUG + 1);
		startArray[i] = AUG;
	}
	do {
		UAA = codeSequence.find("UAA", UAA + 1);
			if (UAA != std::string::npos) {
				countStop++;
				countStopUAA++;
				searchResult = true;
			}
			else
				searchResult = false;
	} while (searchResult == true);
	do {
		UAG = codeSequence.find("UAG", UAG + 1);
			if (UAG != std::string::npos) {
				countStop++;
				countStopUAG++;
				searchResult = true;
			}
			else
				searchResult = false;
	} while (searchResult == true);
	do {
		UGA = codeSequence.find("UGA", UGA + 1);
			if (UGA != std::string::npos) {
				countStop++;
				countStopUGA++;
				searchResult = true;
			}
			else
				searchResult = false;
	} while (searchResult == true);
	
	UAA = -1;
	UAG = -1;
	UGA = -1;
	int *stopArray = new int[countStop];
	for (int i = 0; i < countStopUAA; i++) {
		UAA = codeSequence.find("UAA", UAA + 1);
		stopArray[i] = UAA;
	}
	countStopCurrent = countStopUAA + countStopUAG;
	for (int i = countStopUAA; i < countStopCurrent; i++) {
		UAG = codeSequence.find("UAG", UAG + 1);
		stopArray[i] = UAG;
	}
	for (int i = countStopCurrent; i < countStop; i++) {
		UGA = codeSequence.find("UGA", UGA + 1);
		stopArray[i] = UGA;
	}
	positions = countStop * countStart;
	int *positionArray = new int[positions];
	for (int i = 0; i < countStart; i++) {
		for (int j = 0; j < countStop; j++) {
			positionDifference = stopArray[j] - startArray[i];
			if (positionDifference > 0 && positionDifference % 3 == 0)
				cout << "Possible mRNA sequence starting from nucleotide sequence: " << startArray[i] + 1 << " and " << stopArray[j] + 3 << ".\n";
		}
	}
	}

int main(){
	mRNA();
	startCodon();
	stopCodonUAA();
	stopCodonUAG();
	stopCodonUGA();
	cout << countStop::rnaSequence;
	intronRemoval();
	rnaSequence();
	system("pause");
	return 0;
}