#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


ifstream *open_files(int runs) {
	
	ifstream *obj;
	obj = new ifstream[runs];
	int i;
	string k;
	for (i = 1; i <= runs; i++) {
		k = to_string(i);
		obj[i - 1].open("/Run/file" + k);
	}
/*	for (int it = 0; it < 100; it++) {
		obj[3] >> i;
		cout << i << endl;
	}*/
	return obj;
	
	
}


void arr_sort(vector <int> & myarr) {
	sort(myarr.begin(), myarr.end());	
}

int main(int argc, char *argv[]) {
	ifstream input;
	ofstream output;
	int  i, j = 0, run = 0;
	vector <int> arr;
	input.open(argv[1]);
	if (input.is_open()) {
		while (input >> i) {
			
			for (j = 0; j < 100 && (input >> i) ; j++) {
			//	cout << i << "\t";
				arr.push_back(i);
			}
			run++;
			string str = to_string(run);
			arr_sort(arr);
			output.open("./Run/file" + str);
			for (int k = 0; k < arr.size(); k++) {
				output << arr[k] << endl;
			}
			output.close();
		}
		input.close();

	//	ifstream obj1 = open_files(run);
		ifstream *obj1 = open_files(run);
		int l = 0, m = 0;
		for (int it = 0; it < 100; it++) {
			obj1[3] >> l;
//			cout << l << endl;
		}
	}	
	return 0;
}


