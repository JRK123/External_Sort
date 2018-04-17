#include <iostream>
#include <climits>
#include <cstdio>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;


ifstream * open_files_all(int runs) {
	ifstream *obj;
	obj = new ifstream[runs];
	int i;
	string k;
	for (i = 0; i < runs; i++) {
		k = to_string(i+1);
		obj[i].open("./Run/file" + k);
	}

	return obj;
}

int find_min(vector <int> &vec) {
	int min = vec[0], i, index = 0;
	for (i = 1; i < vec.size(); i++) {
		if (vec[i] < min){
			min = vec[i];
			index = i;
		}
	}
	return index;
}


void arr_sort(vector <int> & myarr) {
	sort(myarr.begin(), myarr.end());	
}

int main(int argc, char *argv[]) {
	ifstream input;
	ofstream output;
	int  i, j = 0, run = 0;
	input.open(argv[1]);
	if (input.is_open()) {
		while (!input.eof()) {
			
			vector <int> arr;
			for (j = 0; (j < 100) && (input >> i) ; j++) {
			//	cout << i << "\t";
				arr.push_back(i);
			}
			if (input.eof())
				break;
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

	}
		ifstream *obj;

		obj = open_files_all(run);

		/*		obj = new ifstream[2];
		obj[0].open("./Run/file1");
		obj[1].open("./Run/file2");*/
		vector <int> vec;
		for (i = 0; i < run; i++) {
			obj[i] >> j;
			vec.push_back(j);
		}
		int index, size = run;
		output.open("sorted_file");
		while (1) {
			index = find_min(vec);
			if (!obj[index].eof()) 
				output << vec[index] << endl;
			if (!obj[index].eof()) {
				obj[index] >> j;
				vec[index] = j;

			}
			else {
				vec[index] = INT_MAX;
				//obj[index].close();
				if (all_of(vec.begin(), vec.end(), [](int i) {return (i == INT_MAX);}))
					break;
			}
		}
		delete [] obj;
		output.close();				
	return 0;
}


