#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
/* Use of & signifies Call by Reference. What it means in short is whatever you change for these variables in the function is
 reflected back to the calling function. So, you need not return values */
bool getInt(ifstream&, bool&, int&, string&);
int getFileSize(ifstream&);
int getLineCount(ifstream&);

int main ()
{
	int intData;
	string junkData;
	bool valueIsGood = false;
	string fileName = "";
	cout << "Enter the input filename: ";
	cin >> fileName;
	cout << endl;
	
	//Open the file in read mode with the ifstream object fin
	ifstream fin(fileName);
	
	//Check if the file opened successfully. If not, exit the program
	if (!fin.is_open()) {
		cerr << "Unable to open file " << fileName << endl;
		exit(10);
	}

	ofstream intFile("intVals.txt");
	ofstream junkFile("junkVals.txt");

	if (!intFile.is_open())
	{
		cerr << "Unable to open file intVals.txt" << endl;
		exit(10);
	}

	if (!junkFile.is_open())
	{
		cerr << "Unable to open file junkVals.txt" << endl;
		exit(10);
	}

	//Print the size of the file
	cout << "File Size: " << getFileSize(fin) << endl; 

	//Print the number of lines
	cout << "Number of lines in the input file: " << getLineCount(fin) << endl;
	
	while (getInt(fin, valueIsGood, intData, junkData)){
		/* Code here: Check if the value in intData is good i.e. integer. This is done by checking valueIsGood boolean
		If value is good, save the intData in intVals.txt else save the junkData in junkVals.txt
		*/
		if (valueIsGood) {
			intFile << intData << endl;
		} else {
			junkFile << junkData << endl;
		}
	}

	// Close the files
	fin.close();
	intFile.close();
	junkFile.close();
	
	cout << "You can now open intVals.txt and junkVals.txt to see the output!" <<endl;
	return 0;
}

int getFileSize(ifstream& fin) {
	int fileSize = 0; //For our case, fileSize will not exceed integer's limit so we do not need long
	//Write the logic to print the file size (in bytes)

	fin.seekg(0, ios::end); //Move the pointer to the end of the file
	fileSize = fin.tellg();
	fin.seekg(0, ios::beg); //Move the pointer back to the beginning of the file

	return fileSize;
}

int getLineCount(ifstream& fin) {
	int count = 0;
	string line;

	fin.clear(); //remove the fail flag
	while (getline(fin, line)) {
		count++;
	}

	fin.clear();
	fin.seekg(0, ios::beg);

	return count;

}

// Function returns False if you cannot continue reading the file i.e. either the EOF or the Bad flag got set
bool getInt(ifstream& fin, bool& goodFlag, int& intData, string& junkData){
	bool canContinue = true;
	// Code the logic here
	fin >> intData;

	if (!fin.fail()) {
		goodFlag = true;
	} else {
		if (fin.eof()){
			canContinue = false;
		} else {
			fin.clear();
			fin >> junkData;

			if (fin.fail()) {
				canContinue = false;
			} else {
				goodFlag = false;
			}
		}
	}


	return canContinue;
}



