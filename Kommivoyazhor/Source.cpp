#include <iostream>
#include <chrono>
#include <random>
#include <vector>
using namespace std;

void fillMatrixRandom(int N, vector<vector<int>> matrix);
int computePermutationCost(vector<vector<int>> matrix, vector<int> permutation);

//Полный перебор и жадный алгоритм

int main()

{
	int townCount, startingTown = 0, bestCost = 0, worstCost = 0;
    chrono::steady_clock::time_point bruteForceStart;
    chrono::steady_clock::time_point bruteForceEnd;
    chrono::nanoseconds bruteForceResultTime;
    chrono::steady_clock::time_point greedyAlgorithmStart;
    chrono::steady_clock::time_point greedyAlgorithmEnd;
    chrono::nanoseconds greedyAlgorithmResultTime;

    vector<int> permutations(townCount);
    vector<int> bestPermutation(townCount);
    vector<int> worstPermutation(townCount);
    vector<bool> visits(townCount);
   

	cout << "Input the number of towns" << endl;
	cin >> townCount;
    vector<vector<int>> priceMatrix(townCount, vector<int>(townCount));

    fillMatrixRandom(townCount, priceMatrix);

    bruteForceStart = chrono::steady_clock::now();

    permutations[0] = startingTown;
    for (int i = 1, k = 0; i < townCount; i++, k++) {
        if (k == startingTown) k++;
        permutations[i] = k;
    }
    vector<int>bestPermutation = permutations;
    vector<int>worstPermutation = permutations;
    bestCost = worstCost = computePermutationCost(priceMatrix, permutations);
    do
    {
        int currentCost = computePermutationCost(priceMatrix, permutations);
        if (currentCost < bestCost) 
        { 
            bestPermutation = permutations; 
            bestCost = currentCost; 
        }
        if (currentCost > worstCost) 
        { 
            worstPermutation = permutations; 
            worstCost = currentCost; 
        }


    } while (next_permutation(permutations.begin(), permutations.end()));
    bruteForceEnd = chrono::steady_clock::now();
    bruteForceResultTime = bruteForceEnd - bruteForceStart;
}

void fillMatrixRandom(int N, vector<vector<int>> matrix)
{

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(1, 20);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
        {
            if (i == j) matrix[i][j] = 0;
            else matrix[i][j] = distrib(gen);
        }
    }
    cout << "Generated price matrix:";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int computePermutationCost(vector<vector<int>> matrix, vector<int> permutation)
{
    int result;
    for (int i = 0; i < permutation.size() - 1; i++)
    {
        result += matrix[permutation[i]][permutation[i + 1]];
    }
    result += matrix[permutation[permutation.size() - 1]][permutation[0]];
    return result;



}
