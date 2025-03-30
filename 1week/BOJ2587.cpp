//백준 2587번 : 대표값2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	vector<int> v;
	int sum = 0;
	double average;
	int mid = 0;


	for (int i = 0; i < 5; i++) 
	{
		v.push_back(i);                      
	}

	for (int i = 0; i < v.size();i++)
	{
		cin >> v[i];
	    sum += v[i];                  
	}
	
	sort(v.begin(), v.end());			
	mid = v[v.size() / 2];				

	average = (double)sum / v.size();		
	
	cout << average << "\n";
	cout << mid << "\n";

	return 0;
}