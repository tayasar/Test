#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int findFirstIndex(string text, string image);
vector<int> findAllIndex(string text, string image);
vector<int> findIndexInRange(string text, string image, int start, int end);

int main()
{
	int result1, resultFail1; vector<int> result2, resultFail2, result3, restultFail4;

	result1 = findFirstIndex("AABABCBA", "BC");
	cout << result1 << endl;

	resultFail1 = findFirstIndex("AABABCBA", "EEE");
	cout << resultFail1 << endl;

	result2 = findAllIndex("AABABCBAAHAA", "AA");
	for (int idx : result2) cout << idx << " ";
	cout << endl;

	resultFail2 = findAllIndex("AABABCBAAHAA", "GR");
	for (int idx : resultFail2) cout << idx << " ";
	cout << endl;

	result3 = findIndexInRange("AABABCBAAHAA", "AA", 7, 11);
	for (int idx : result3) cout << idx << " ";
	cout << endl;

	restultFail4 = findIndexInRange("", "", 0, 11);
	for (int idx : restultFail4) cout << idx << " ";
}

int findFirstIndex(string text, string image)
{
	int TAB[256], i, m, n, k, j;
	n = text.size(); m = image.size();
	if (m == 0 || n == 0 || m > n) return -1;

	for (i = 0; i < 256; i++)
		TAB[i] = m;
	for (i = 0; i < m - 1; i++)
		TAB[image[i]] = (m - 1 - i);

	i = m - 1;
	while (i < n)
	{
		k = i; j = m - 1;
		while (j >= 0)
		{
			if (text[k] == image[j])
			{
				k--; j--;
			}
			else break;
		}
		if (j < 0)
		{
			k++;
			return k;
		}

		else i += (TAB[text[i]]);
	}
	if (!(i < n)) return -1;
}

vector<int> findAllIndex(string text, string image)
{
	int TAB[256], i, m, n, k, j; bool indexOccurence = false;
	vector<int> indexes;
	n = text.size(); m = image.size();
	if (m == 0 || n == 0 || m > n) { indexes.push_back(-1); return indexes; }
	

	for (i = 0; i < 256; i++)
		TAB[i] = m;
	for (i = 0; i < m - 1; i++)
		TAB[image[i]] = (m - 1 - i);

	i = m - 1;
	while (i < n)
	{
		k = i; 
		j = m - 1;
		while (j >= 0)
		{
			if (text[k] == image[j])
			{
				k--; j--;
			}
			else break;
		}
		if (j < 0)
		{
			k++;
			indexes.push_back(k);
			indexOccurence = true;
		}
		i += (TAB[text[i]]);
	}
	if (!indexOccurence)
	{
		indexes.push_back(-1);
	}
	return indexes;
}

vector<int> findIndexInRange(string text, string image, int start, int end)
{
	int TAB[256], i, m, n, k, j; bool indexOccurence = false;
	vector<int> indexes;
	n = text.size(); m = image.size();
	if (start > end || (end - start + 1) < m || m == 0 || n == 0 || m > n) { indexes.push_back(-1); return indexes; }
	if (start < 0) start = 0; 
	if (end >= n) end = n - 1;
	

	for (i = 0; i < 256; i++)
		TAB[i] = m;
	for (i = 0; i < m - 1; i++)
		TAB[image[i]] = (m - 1 - i);

	i = start + m - 1;
	while (i <= end)
	{
		k = i;
		j = m - 1;
		while (j >= 0)
		{
			if (text[k] == image[j])
			{
				k--; j--;
			}
			else break;
		}
		if (j < 0)
		{
			k++;
			indexes.push_back(k);
			indexOccurence = true;
		}
		i += (TAB[text[i]]);
	}
	if (!indexOccurence)
	{
		indexes.push_back(-1);
	}
	return indexes;
}