#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
const int ALPHABET_SIZE = 256;

int findFirstIndex(const string& text, const string& image);
vector<int> findAllIndex(const string& text, const string& image);
vector<int> findIndexInRange(const string& text, const string& image, int start, int end);

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

int findFirstIndex(const string& text, const string& image)
{
	int TAB[ALPHABET_SIZE], imageSize, textSize, i, k, j;
	textSize = text.size(); imageSize = image.size();
	if (imageSize == 0 || textSize == 0 || imageSize > textSize) return -1;

	for (i = 0; i < ALPHABET_SIZE; i++)
		TAB[i] = imageSize;
	for (i = 0; i < imageSize - 1; i++)
		TAB[image[i]] = (imageSize - 1 - i);

	i = imageSize - 1;
	while (i < textSize)
	{
		k = i; j = imageSize - 1;
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
	if (!(i < textSize)) return -1;
}

vector<int> findAllIndex(const string& text, const string& image)
{
	int TAB[ALPHABET_SIZE], imageSize, textSize, i, k, j; bool indexOccurence = false;
	vector<int> indexes;
	textSize = text.size(); imageSize = image.size();
	if (imageSize == 0 || textSize == 0 || imageSize > textSize) { indexes.push_back(-1); return indexes; }
	

	for (i = 0; i < ALPHABET_SIZE; i++)
		TAB[i] = imageSize;
	for (i = 0; i < imageSize - 1; i++)
		TAB[image[i]] = (imageSize - 1 - i);

	i = imageSize - 1;
	while (i < textSize)
	{
		k = i; 
		j = imageSize - 1;
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

vector<int> findIndexInRange(const string& text, const string& image, int start, int end)
{
	int TAB[ALPHABET_SIZE], imageSize, textSize, i, k, j; bool indexOccurence = false;
	vector<int> indexes;
	textSize = text.size(); imageSize = image.size();
	if (start > end || (end - start + 1) < imageSize || imageSize == 0 || textSize == 0 || imageSize > textSize) { indexes.push_back(-1); return indexes; }
	if (start < 0) start = 0; 
	if (end >= textSize) end = textSize - 1;
	

	for (i = 0; i < ALPHABET_SIZE; i++)
		TAB[i] = imageSize;
	for (i = 0; i < imageSize - 1; i++)
		TAB[image[i]] = (imageSize - 1 - i);

	i = start + imageSize - 1;
	while (i <= end)
	{
		k = i;
		j = imageSize - 1;
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