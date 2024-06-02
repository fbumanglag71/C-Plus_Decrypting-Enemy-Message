/*Author: Francisco Bumanglag
Project: Decrypting Enemy Message
Assignment: Module 15 Project 12
Course: C++ Santa Ana College
Class: CMPR120 Dr. Tahir Aziz
Date: June 2, 2024*/

#include <iostream>		//standard input/output operations
#include <string>		//string handling capabilities 

using namespace std;	//access standard library symbols directly

//function to decrypt a single character with a given key
char decryptChar(char encryptedChar, int Key) {
	int decryptedChar = encryptedChar - Key; 
	if (decryptedChar < 32) 
	{
		decryptedChar += 95; //wrap around within the printable ASCII range
	}
	//converts integer back to character after decryption
	return static_cast<char>(decryptedChar);

}

//function to decrypt an entire message with a given key 
string decryptMessage(const string& encryptedMessage, int Key) {

	string decryptedMessage;
	for (char encryptedChar : encryptedMessage) {
		decryptedMessage += decryptChar(encryptedChar, Key);
}
	//return the decrypted message as a string
	return decryptedMessage; 
}

int main() {
	string encryptedMesssage;
	
	//user inputs the encrypted message
	cout << "Enter the encrypted message: "; 
	getline(cin, encryptedMesssage); 
	cout << endl; 

	//loop decrypts message using keys 1 to 100
	for (int Key = 1; Key <= 100; ++Key) {
		cout << "Key " << Key << ": " << decryptMessage(encryptedMesssage, Key) << endl;
	}
	return 0;  //successful completion of the program
}
