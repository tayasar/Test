#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int findFirstIndex(string text, string image);
vector<int> findAllIndex(string text, string image);

int main()
{
	findFirstIndex("AABABCBA", "BC");
	findFirstIndex("AABABCBA", "EEE");
	findAllIndex("AABABCBAAHAA", "AA");
	findAllIndex("AABABCBAAHAA", "GR");
}

int findFirstIndex(string text, string image)
{
	int TAB[256], i, m, n, k, j;
	n = text.size(); m = image.size();
	cout << "text lenght = " << n << ", image length = " << m << endl;

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
			cout << "Image ocurrence start index = " << k << endl;
			return k;
		}

		else i += (TAB[text[i]]);
	}
	if (!(i < n))
		cout << "Image not found" << endl;
	return -1;
}

vector<int> findAllIndex(string text, string image)
{
	int TAB[256], i, m, n, k, j; bool indexOccurence = false;
	vector<int> indexes;
	n = text.size(); m = image.size();
	cout << "text lenght = " << n << ", image length = " << m << endl;

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
			cout << "Image ocurrence start index = " << k << endl;
			indexes.push_back(k);
			indexOccurence = true;
		}
		i += (TAB[text[i]]);
	}
	if (!indexOccurence)
	{
		cout << "Image not found" << endl;
		indexes.push_back(-1);
	}
	return indexes;
}

void findIndexInRange()
{

}