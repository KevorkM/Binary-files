#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Data {
	int value1;
	int value2;
};

int main() {

	cout << "Reading from a file\n" << endl;

	srand(time(NULL));

	const int Max = 10;

	const int Value1_Max = 100;
	const int Value2_Max = 1000;

	Data ArrayData[Max];

	for (int i = 0; i < Max; i++) {
		ArrayData[i].value1 = rand() % Value1_Max + 1;
		ArrayData[i].value2 = (rand() % (Value2_Max - Value1_Max)) + Value1_Max + 1;

		cout << "ArrayData[" << i << "].value1: " << ArrayData[i].value1 << endl;
		cout << "ArrayData[" << i << "].value2: " << ArrayData[i].value2 << endl;

	}

	ofstream outFile;

	outFile.open("Data.bin", fstream::binary);
	outFile.write((char*)&ArrayData, sizeof(ArrayData));
	outFile.close();

	Data NewArray[Max];

	ifstream inFile;

	inFile.open("Data.bin",fstream::binary);
	inFile.read((char*)&NewArray, sizeof(NewArray));
	inFile.close();

	for (int i = 0; i < Max; i++) {
		cout << "NewArray[" << i << "]value1: " << NewArray[i].value1 << endl;
		cout << "NewArray[" << i << "]value2: " << NewArray[i].value2 << endl;
	}

	return 0;
}