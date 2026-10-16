#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void fillMatrixRandom(int N, vector<vector<int>>& matrix);
int computePermutationCost(const vector<vector<int>>& matrix, const vector<int>& permutation);
void outputPath(const vector<int>& permutation);
bool nextPermutation(vector<int>& permutation, int townCount);

//Полный перебор и жадный алгоритм

int main()

{
	int townCount, startingTown = 0, bestCost = 0, worstCost = 0, greedyAlgorithmCost = 0;
    double accuracyPercentage;
    chrono::steady_clock::time_point bruteForceStart;
    chrono::steady_clock::time_point bruteForceEnd;
    chrono::nanoseconds bruteForceResultTime;
    chrono::steady_clock::time_point greedyAlgorithmStart;
    chrono::steady_clock::time_point greedyAlgorithmEnd;
    chrono::nanoseconds greedyAlgorithmResultTime;

    cout << "Input the number of towns (number > 0): ";
    cin >> townCount;
    if (townCount <= 0)
    {
        cout << "Error: invalid number of towns";
        return 0;
    }

    vector<int> permutations(townCount);
    vector<int> greedyPermutation(townCount);
    vector<int> bestPermutation(townCount);
    vector<int> worstPermutation(townCount);
    vector<bool> visits(townCount, false);
   
    vector<vector<int>> priceMatrix(townCount, vector<int>(townCount));

    fillMatrixRandom(townCount, priceMatrix);

    bruteForceStart = chrono::steady_clock::now();

    permutations[0] = startingTown;
    for (int i = 1, k = 1; i < townCount; i++, k++) 
    {
        permutations[i] = k;
    }
    bestPermutation = permutations;
    worstPermutation = permutations;
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
    } while (nextPermutation(permutations, townCount));

    bruteForceEnd = chrono::steady_clock::now();
    bruteForceResultTime = bruteForceEnd - bruteForceStart;

    cout << "Brute force time: " << bruteForceResultTime.count() << " nanoseconds" << endl;
    cout << "Brute force best path: ";
    outputPath(bestPermutation);
    cout << "Best cost = " << bestCost << endl;
    cout << "Brute force worst path: ";
    outputPath(worstPermutation);
    cout << "Worst cost = " << worstCost << endl;

    greedyAlgorithmStart = chrono::steady_clock::now();

    greedyPermutation[0] = startingTown;
    visits[startingTown] = true;
    for (int i = 0; i < townCount - 1; i++)
    {
        int nextTown = -1;
        int bestTownCost = INT_MAX;
        for (int j = 0; j < townCount; j++)
        {
            if (!visits[j] && priceMatrix[greedyPermutation[i]][j] < bestTownCost)
            {
                bestTownCost = priceMatrix[greedyPermutation[i]][j];
                nextTown = j;
            }
        }
        greedyPermutation[i + 1] = nextTown;
        visits[nextTown] = true;
    }
    greedyAlgorithmCost = computePermutationCost(priceMatrix, greedyPermutation);
  
    greedyAlgorithmEnd = chrono::steady_clock::now();
    greedyAlgorithmResultTime = greedyAlgorithmEnd - greedyAlgorithmStart;

    cout << "Greedy Algorithm time: " << greedyAlgorithmResultTime.count() << " nanoseconds" << endl;
    cout << "Greedy Algorithm path: ";
    outputPath(greedyPermutation);
    cout << "Greedy algorithm result cost = " << greedyAlgorithmCost << endl;

    if (worstCost != bestCost)
    {
        accuracyPercentage = 100 - (greedyAlgorithmCost - bestCost) * 100. / (worstCost - bestCost);
    }
    else accuracyPercentage = 100;
    cout << "Greedy algorithm is " << accuracyPercentage << "% accurate" << endl;
}

void fillMatrixRandom(int townCount, vector<vector<int>>& matrix)
{

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(1, 20);

    for (int i = 0; i < townCount; i++) {
        for (int j = 0; j < townCount; j++)
        {
            if (i == j) matrix[i][j] = 0;
            else matrix[i][j] = distrib(gen);
        }
    }
    cout << "Generated price matrix:" << endl;
    for (int i = 0; i < townCount; i++) {
        for (int j = 0; j < townCount; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int computePermutationCost(const vector<vector<int>> &matrix, const vector<int>& permutation)
{
    int result = 0;
    for (int i = 0; i < permutation.size() - 1; i++)
    {
        result += matrix[permutation[i]][permutation[i + 1]];
    }
    result += matrix[permutation[permutation.size() - 1]][permutation[0]];
    return result;
}
void outputPath(const vector<int>& permutation)
{
    for (int i = 0; i < permutation.size(); i++)
        cout << permutation[i] << " ";
}
bool nextPermutation(vector<int>& permutation,  int townCount)
{
    int j = townCount - 1;
    int i = townCount - 2;
    while (0 < i && permutation[i] > permutation[i + 1])
    {
        i--;
    }
    if (i == 0) return false;
    while (permutation[j] < permutation[i] && j > i)
    {
        j--;
    }
    swap(permutation[i], permutation[j]);
    reverse(&permutation[i + 1], &permutation[townCount-1]);
    return true;
}

