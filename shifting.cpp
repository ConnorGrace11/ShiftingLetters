#include <iostream>
#include <vector>


using namespace std;

//vector<int>& change
void shifting(string s) {
	int sLen = s.length();
	vector<int> shift;
	int num;
	cout << "please input " << sLen << " integers greater than 0 and less than 25" << endl;
	//get user input to determine how much they would like to shift each letter by.
	//if it is not a number or if it shifts more than 25 times or less than 0 times, then the user must try again with the proper inputs
	try {
		for (int i = 0; i < sLen; i++) {

			cin >> num;
			if (num > 0 && num < 26 && isdigit(num) == false) {
				shift.push_back(num);
			}
			else {
				throw 505;
			}
		}
		string final = "";
		char a;

		//print each character in the original string input
		for (int i = 0; i < s.length(); i++) {
			cout << s[i] << endl;
		}
		
		// shift each character in the string using their ascii values, and if they go past z, they wrap back around to a
		for (int i = 0; i < s.length(); i++) {

			a = s[i];
			int finChar = int(a + shift[i]);
			char adjusted = char(a + shift[i]);
			int exceedsBy;
			if (finChar > int('z')) {
				exceedsBy = finChar - int('z');
				adjusted = char('a' + exceedsBy);
			}
			final = final + char(adjusted);




		}

		cout << final << endl;
	}
	catch (...) {
		cout << "Make sure you are selecting an INTEGER between 0 and 25!" << endl;
	}
				
}

//method to allow the user to input the string they want shifted, as well as making sure that they are only creating strings with letters
string inputString() {
	string original;
	cout << "Please input a string that you would like to shift!" << endl;
	try {
		cin >> original;
		for (int i = 0; i < original.length(); i++) {
			if (isalpha(original[i])) {
				continue;
			}
			else {
				throw 505;
			}
		}
	}
	catch (...) {
		cout << "Please make sure that you are only selecting letters!" << endl;
	}
	return original;
}

int main() {
	
	shifting(inputString());
}