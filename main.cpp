#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main(){
	vector<string> in;
	string temp;
	int startTag;
	int number = 0;
	bool isTag = false, isComment = false;
	fstream file("code.txt");
	if (!file.is_open()) return -1; 
	while (file){
		getline(file, temp);
		in.insert(in.end(), temp);
	}
	for (size_t i = 0 ; i < in.size() ; i++){
		if (in[i].find("/**", 0) != -1) isComment = true;
		if (isComment){
			if (!isTag) startTag = in[i].find("\\func", 0); 
			else if (in[i].find("*/") != 0) cout << "\n";
			if (startTag != -1 && !isTag) {
				isTag = true;
				startTag += 6; 
				cout << ++number << ". ";
			}
			for (int j = 0; isTag && j < in[i].size(); j++){
				if (j == in[i].find("*/")) {
					isTag = false;
					isComment = false;
					cout << "\n";
					break;
				}
				if (j >= startTag) cout << in[i][j];
			}
		if (isTag) startTag = 0;
		}
	}
	system ("pause");
	return 0;
}