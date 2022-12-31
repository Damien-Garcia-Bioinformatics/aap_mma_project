#include <string>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <iostream>
#include <utility>

typedef long long lld;
typedef unsigned long long llu;

int n, m, mtch, msmtch, gap, S;
std::string A, B;
int dp[100][100];

int needle_wurst()
{
	for (int i=0; i<=n; i++) {
		dp[i][0] = -i * gap;
		dp[0][i] = -i * gap;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (A[i-1] == B[j-1]){S = mtch;}
			else {S = -msmtch;}
			dp[i][j] = std::max(dp[i-1][j-1] + S, std::max(dp[i-1][j] - gap, dp[i][j-1] - gap));
		}
	}
	return dp[n][m];
}

std::pair<std::string,std::string> align()
{
	std::string AA, BB;
	std::stack<char> SA, SB;
	int ii = n, jj = m, S = 0;
	while (ii != 0 || jj != 0){
		if (ii == 0){
			SA.push('-');
			SB.push(B[jj-1]);
			jj--;
		}
		else if (jj == 0){
			SA.push(A[ii-1]);
			SB.push('-');
			ii--;
		}
		else {
			if (A[ii-1] == B[jj-1]){S = mtch;}
			else {S = -msmtch;}

			if (dp[ii][jj] == dp[ii-1][jj-1] + S){
				SA.push(A[ii-1]);
				ii--;
				SB.push(B[jj-1]);
				jj--;
			}
			else if (dp[ii][jj] > dp[ii-1][jj-1]){
				SA.push(A[ii-1]);
				SB.push('-');
				ii--;
			}
			else {
				SA.push('-');
				SB.push(B[jj-1]);
				jj--;	
			}

		}
	
	}
	while (!SA.empty()){
		AA += SA.top();
		BB += SB.top();
		SA.pop();
		SB.pop();
	}
	return std::make_pair(AA,BB);

}

int main(){
	n = 5, m = 6;
	mtch = 2, msmtch = 1, gap = 1;
	A = "CATGT";
	B = "ACGCTG";
	std::cout << needle_wurst() << std::endl;
	std::cout << align().first.c_str() << "\n" << align().second.c_str() << std::endl;
	return 0;
}
