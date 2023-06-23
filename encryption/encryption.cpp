#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;
vector<vector<int>> generateFibonacciMatrix(int num) {
vector<vector<int>> matrix;
int fib1 = 0, fib2 = 1, fib3 = 1;
while (num > 0) {
vector<int> row;
while (fib3 <= num) {
fib1 = fib2;
fib2 = fib3;
fib3 = fib1 + fib2;
}
num -= fib2;
row.push_back(fib2);
fib1 = 0;
fib2 = 1;
fib3 = 1;
matrix.push_back(row);
}
return matrix;
}
vector<vector<int>> encrypt(string plaintext, string key) {
vector<vector<int>> binaryMatrix;
vector<int> firstRow;
int firstPlaintextChar = plaintext[0];
int firstKeyChar = key[0];
int firstXORResult = firstPlaintextChar ^ firstKeyChar;
firstRow.push_back(firstXORResult);
for (int j = 1; j < key.size(); j++) {
vector<int> row;
int plaintextChar = plaintext[j];
int keyChar = key[j];
int xorResult = plaintextChar ^ keyChar;
row.push_back(xorResult);
binaryMatrix.push_back(row);
}
binaryMatrix.insert(binaryMatrix.begin(), firstRow);
// Convert each row to its series and store it in an array of strings
vector<vector<int>> seriesMatrix;
for (int i = 0; i < binaryMatrix.size(); i++) {
vector<int> rowSeries;
for (int j = 0; j < binaryMatrix[i].size(); j++) {
int num = binaryMatrix[i][j];
vector<vector<int>> fibonacciMatrix = generateFibonacciMatrix(num);
for (int k = 0; k < fibonacciMatrix.size(); k++) {
rowSeries.push_back(fibonacciMatrix[k][0]);
}
}
seriesMatrix.push_back(rowSeries);
}
return seriesMatrix;
}
void printMatrix(vector<vector<int>> matrix) {
for (int i = 0; i < matrix.size(); i++) {
for (int j = 0; j < matrix[i].size(); j++) {
cout << matrix[i][j] << " ";
}
cout << endl;
}
}
int main() {
string plaintext, key;
cout << "Enter plaintext: ";
getline(cin, plaintext);
cout << "Enter key equivalent to plaintext: ";
getline(cin, key);
vector<vector<int>> seriesMatrix = encrypt(plaintext, key);
cout << "Series Matrix:" << endl;
printMatrix(seriesMatrix);
return 0;
