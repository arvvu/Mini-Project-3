#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


vector<vector<int>> input;
vector<vector<int>> output;



string currentLine;
int currentNumber;
int rows;
int columns;


int meanFilter(vector<vector<int>> in, int row, int column) { //Takes mean of 3x3 grid centered at (row, column) and returns it
    
    int sum = 0;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            sum += in[row + i][column + j];
        }
    }

    int result = sum / 9;

    if (result < 0) {
        result = 0;
    }

    if (result > 255) {
        result = 255;
    }

    return result;
}


int main() {
    
    int fileRow = 0;
    int vectorRow = 0;
    int vectorColumn = 0;

    string oFileName;
    string iFileName;

    cout << "Enter input file name and output file name:" << endl;
    cin >> iFileName >> oFileName;

    string iPath = "tests/" + iFileName;
    ifstream inputFile(iPath);

    while(getline(inputFile, currentLine)) { // Read input to vector
        
        if (fileRow == 0) {
            istringstream ss(currentLine);
            ss >> rows >> columns;
            fileRow++;
            input.resize(rows, vector<int>(columns));
            output.resize(rows, vector<int>(columns));
            continue;
        }
        istringstream ss(currentLine);
        while (ss >> currentNumber) {
            
            input[vectorRow][vectorColumn] = currentNumber;
            vectorColumn++;
            
        }
        fileRow++;
        vectorRow++;
        vectorColumn = 0;
        

        
        
    }

    inputFile.close();

    for (int i = 0; i < rows; i++) { //Apply filter to input and save to output vector
        if (i == 0 || i == rows - 1) {
            for (int j = 0; j < columns; j++) {
                output[i][j] = input[i][j];
            }
            continue;
        }
        for (int j = 0; j < columns; j++) {
            if (j == 0 || j == columns - 1) {
                output[i][j] = input[i][j];
                continue;
            }
            output[i][j] = meanFilter(input, i, j);
        }
    }

    string oPath = "tests/" + oFileName;
    ofstream outputFile(oPath);

    for (int i = 0; i < rows; i++) { //Write output vector to output.txt
        for (int j = 0; j < columns; j++) {
            outputFile << output[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}

