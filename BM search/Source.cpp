#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int findFirstIndex(string text, string image);

int main()
{
	findFirstIndex("AABABCBA", "BC");
	findFirstIndex("AABABCBA", "EEE");
}

int findFirstIndex(string text, string image)
{
	int TAB[256], i, m, n, k, j, cnt;
	n = text.size(); m = image.size();
	cout << "text lenght = " << n << ", image length = " << m << endl;

	for (i = 0; i < 256; i++)
		TAB[i] = m;
	for (i = 0; i < m - 1; i++)
		TAB[image[i]] = (m - 1 - i);

	i = m - 1;
	while (i < n)
	{
		k = i; j = m - 1; cnt = 0;
		while (j >= 0)
		{
			if (text[k] == image[j])
			{
				k--; j--; cnt++;
			}
			else break;
		}
		if (j < 0)
		{
			k++;
			cout << "Image start index = " << k << endl;
			return k;
		}

		else i += (TAB[text[k]] - cnt);
	}
	if (!(i < n))
		cout << "Image not found";
	return -1;



}

void findAllIndex()
{

}

void findIndexInRange()
{

}