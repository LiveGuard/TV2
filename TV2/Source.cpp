#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
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

void taskTwo()
{

}

int main()
{
	taskOne();
	taskTwo();
	return 0;
}