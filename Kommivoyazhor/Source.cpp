#include <iostream>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

int main()

{
	int townCount, startingTown;

    vector<int> visits(townCount);

	cout << "Input the number of towns" << endl;
	cin >> townCount;
	cout << "Input the starting town" << endl;
	cin >> startingTown;

    vector<vector<int>> priceMatrix(townCount, vector<int>(townCount));

    fillMatrix(townCount, priceMatrix);


}

void fillMatrix(int N, vector<vector<int>> matrix) 
{

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(1, 20);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = distrib(gen); 
        }
    }
    cout << "Generated price matrix:";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

