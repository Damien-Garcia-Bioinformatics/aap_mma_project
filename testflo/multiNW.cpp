#include <string>
#include <stdio.h>
#include <stack>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <iostream>
#include <utility>


int  mtch, msmtch, gap, S;


std::vector<std::vector<int>> needle_wurst(int n, int m, std::vector<std::string> A, std::vector<std::string> B)
{
	std::vector<std::vector<int>> score_matrix;
	for (int i=0; i<=n; i++) {
		score_matrix[i][0] = -i * gap;
		score_matrix[0][i] = -i * gap;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (A[i-1] == B[j-1]){S = mtch;}
			else {S = -msmtch;}
			score_matrix[i][j] = std::max(score_matrix[i-1][j-1] + S, std::max(score_matrix[i-1][j] - gap, score_matrix[i][j-1] - gap));
		}
	}
	return score_matrix;
}

void read_trace(std::string &line, std::vector<std::string> &trace) {
	std::string temp ;
	for (size_t i=0 ; i<line.size() ; i++) {
		if (line[i] == ' ') {
			trace.push_back(temp) ;
		} else {
			temp += trace[i] ;
		}
	}
	// Last value push back in vector.
	if (!temp.empty()) {
		trace.push_back(temp) ;
	}
}


void read_file(std::string &path, std::vector<std::vector<std::string>> &traces) {
	std::ifstream file ;
	file.open(path) ;
	if (file.is_open()) {
		std::string line ;
		while (getline(file, line)) {
			if (line[0] != '#' && !line.empty()){
				std::vector<std::string> trace ;
				read_trace(line, trace) ;
				traces.push_back(trace) ;
				trace.clear() ;}
		}
	}
	file.close() ;
}


std::vector<std::vector<std::string>> align(std::vector<std::vector<std::string>> Input_List)
{
	std::string gappy {" - "};
	std::vector<std::vector<std::string>> Output_List;
	std::vector<std::string> uno, dos, resultuno, resultodos;
	uno = Input_List[0];
	dos = Input_List[1];

	for (size_t i=0 ; i<Input_List.size()-1 ; i++) {

		
		std::vector<std::vector<int>> score_matrix = needle_wurst(uno.size(), dos.size(), uno, dos) ;
		int ii = uno.size(), jj = dos.size(), stack;
		while (ii != 0 || jj != 0){
			if (ii == 0){
				resultuno.push_back(gappy);
				resultodos.push_back(dos[jj-1]);
				jj--;
			}
			else if (jj == 0){
				resultuno.push_back(uno[ii-1]);
				resultodos.push_back(gappy);
				ii--;
			}
			else {
				if (uno[ii-1] == dos[jj-1]){stack = mtch;}
				else {stack = -msmtch;}

				if (score_matrix[ii][jj] == score_matrix[ii-1][jj-1] + stack){
					resultuno.push_back(uno[ii-1]);
					ii--;
					resultodos.push_back(dos[jj-1]);
					jj--;
				}
				else if (score_matrix[ii][jj] > score_matrix[ii-1][jj-1]){
					resultuno.push_back(uno[ii-1]);
					resultodos.push_back(gappy);
					ii--;
				}
				else {
					resultuno.push_back(gappy);
					resultodos.push_back(dos[jj-1]);
					jj--;	
				}

			}
		
		}
		Output_List.push_back(resultuno);
		uno = resultodos;
		dos = Input_List[i+2];
		std::vector<std::string> dernier_pas_opti = resultodos;
		resultuno.clear();
		resultodos.clear();
	}
	return Output_List;
}

std::vector<std::vector<std::string>> Sort_Best (std::vector<std::vector<std::string>> Unsorted){
	int max = 0;
	int index = 0;
	for (int i = 0; i < Unsorted.size(); i++){
		if (Unsorted[i]>max){max = Unsorted[i]; index = i; }
	}
	for (int i = 0; i < max; i++){
	for (int j = 0; j < Unsorted.size(); j++){
		int maxcount = 0;
	    int element_having_max_freq;
	    for (int i = 0; i < n; i++) {
	        int count = 0;
	        for (int j = 0; j < n; j++) {
	            if (arr[i] == arr[j])
	                count++;
	        }
	        if (count > maxcount) {
	            maxcount = count;
	            element_having_max_freq = arr[i];
	        }
	    }
	}}


}

int main(){
	mtch = 1;
	msmtch = 1;
	gap = 1;
	S = 0;
	//std::ifstream file ;
	//file.open("result_complex.txt") ;
	//if (file.is_open()) {
	//	std::string line ;
	//	while (getline(file, line)) {
	//		std::cout << line << std::endl;
	//	}
	//}		
	std::vector<std::vector<std::string>> input;
	//std::string filepath = "result_complex.txt";
	//read_file(filepath, input);
	
	std::vector<std::string> trace;
	trace.push_back("a");
	trace.push_back("---");
	trace.push_back("b");
	trace.push_back("c");
	input.push_back(trace);
	
	trace.clear();
	trace.push_back("a");
	trace.push_back("--");
	trace.push_back("b");
	trace.push_back("-");
	trace.push_back("c");
	input.push_back(trace);
	trace.clear();
	trace.push_back("a");
	trace.push_back("b");
	trace.push_back("--");
	trace.push_back("c");
	input.push_back(trace);
	trace.clear();
	for (int i = 0; i < input.size();i++){for (int j=0;j<input[i].size();j++){ std::cout << input[i][j] << std::endl;}}
	//std::vector<std::vector<std::string>> output = align(input);
	//for (int i = 0; i < output.size();i++){std::cout << output[i][0] << std::endl;}

	return 0;
}
