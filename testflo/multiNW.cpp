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

typedef int[100][100] tableau_val;

int  mtch, msmtch, gap, S;


tableau_val needle_wurst(int n, int m, std::vector<std::string> A, std::vector<std::string> B)
{
	int score_matrix[100][100];
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
			std::vector<std::string> trace ;
			read_trace(line, trace) ;
			traces.push_back(trace) ;
			trace.clear() ;
		}
	}
	file.close() ;
}


std::vector<std::string> align(std::vector<std::vector<std::string>> Input_List)
{
	std::vector<std::vector<std::string>> Output_List;
	for (size_t i=0 ; i<Input_List.size()-1 ; i++) {

		
		int score_matrix = needle_wurst(Input_List[i].size(), Input_List[i+1].size(), Input_List[i], Input_List[i+1]) ;
		int ii = Input_List[i].size(), jj = Input_List[i+1].size(), stack;
		while (ii != 0 || jj != 0){
			if (ii == 0){
				Output_List[i].push_back('-');
				Output_List[i+1].push_back(Input_List[i+1][jj-1]);
				jj--;
			}
			else if (jj == 0){
				Output_List[i].push_back(Input_List[i][ii-1]);
				Output_List[i+1].push_back('-');
				ii--;
			}
			else {
				if (Input_List[i][ii-1] == Input_List[i+1][jj-1]){stack = mtch;}
				else {stack = -msmtch;}

				if (score_matrix[ii][jj] == score_matrix[ii-1][jj-1] + stack){
					Output_List[i].push_back(Input_List[i][ii-1]);
					ii--;
					Output_List[i+1].push_back(Input_List[i+1][jj-1]);
					jj--;
				}
				else if (score_matrix[ii][jj] > score_matrix[ii-1][jj-1]){
					Output_List[i].push_back(Input_List[i][ii-1]);
					Output_List[i+1].push_back('-');
					ii--;
				}
				else {
					Output_List[i].push_back('-');
					Output_List[i+1].push_back(Input_List[i+1][jj-1]);
					jj--;	
				}

			}

		}
		
		return Output_List;
	}
}

int main(){
	return 0;
}
