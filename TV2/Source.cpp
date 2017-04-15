#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

#define start (100)
#define finish (start + 99)
 
void taskOne()
{
	int i;
	double j, Xu;
	vector<double> msv;
	vector<int> count(10);

	for (i = start; i <= finish; i++)
	{
		j = fabs(round((1 / tan(i)) * 1000) / 1000);
		double x = modf(j, &j);
		x *= 10;
		x = modf(x, &j);
		x *= 10;
		modf(x, &x);

		msv.push_back(x);
	}

	for (i = 0; i < 100; i++)
		count[msv[i]]++;

	for (i = Xu = 0; i < 10; i++)
		Xu += pow((count[i] - 10),2) / (10);

	cout << "Xu^2 = " << Xu << endl;
}

enum zhanr {
	sport, habr, nabokov
};

vector<int> read(zhanr t)
{
	int i;
	ifstream fin;
	string file, text;
	vector<int> ABC(32);

	if (t == sport)  fin.open("1.txt");
	else if (t == habr) fin.open("2.txt");
	else if (t == nabokov) fin.open("3.txt");

	while (fin)
	{
		getline(fin, file);
		text += file;
	}

	vector<unsigned char> unsText;
	for (i = 0; i < text.size(); i++)
		unsText.push_back(text[i]);

	for (i = 0; i < unsText.size(); i++)
		if (unsText[i] < 224 && unsText[i] > 191)
			ABC[unsText[i] - 192]++;
		else if (unsText[i] > 223 && unsText[i] < 256)
			ABC[unsText[i] - 224]++;

	fin.close();
	return ABC;
}

void taskTwo()
{
	vector<vector<int>> ABC;
	ABC.push_back(read(sport));
	ABC.push_back(read(habr));
	ABC.push_back(read(nabokov));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	taskOne();
	taskTwo();
	return 0;
}