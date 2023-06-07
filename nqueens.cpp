//ARAM ISIKBAY

#include <iostream>
#include <vector>

//Determine if column of the next available row is safe
bool isSafe(std::vector<int> queens, int col) {
	for (int i = 0; i < queens.size(); i++) {
		//If column is already taken OR column has a threatening diagonal
		if ((queens[i] == col || queens.size() - i == abs(col - queens[i]))) {
			return false;
		}
	}
	return true;
}

void printBoard(std::vector<int> queens, int n) {
	//Iterate through board positions, top-down
	for (int i = n - 1; i >= 0; i--) {
		//For each column index, if a queen is at that column in that row, print the queen
		for (int j = 0; j < n; j++) {
			if (j == queens[i]) {
				std::cout << "Q ";
			}
			else {
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
}

void nQueens(std::vector<int> queens, int n) {
	//First queen will take the first available position
	int testColumn = 0;
	//Loop will terminate when all n queens are placed
	while (queens.size() < n) {
		//Place a queen in testColumn if it is safe and in bounds
		if (isSafe(queens, testColumn) && testColumn < n) {
			queens.push_back(testColumn);
			if (queens.size() == n) {
				std::cout << "Solution for n= " << n << " found:" << std::endl;
				printBoard(queens, n);
			}
			//Reset column position for next row
			testColumn = 0;
		}
		//When the testColumn is not safe, advance to the next column if there is space
		else if (testColumn < n - 1) {
			testColumn++;
		}
		//If there is no space, backtrack, trying the next available position for the previous queen
		else {
			testColumn = queens.back() + 1;
			queens.pop_back();
		}
	}
}

int main() {
	int n;
	int fullRows = 0;
	//Stores column positions of n queens. The row is not stored, as it is the index of that element
	std::vector<int> queens;
	std::cout << "n: ";
	std::cin >> n;
	nQueens(queens, n);
	return 0;
}