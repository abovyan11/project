#include <iostream>
#include <string>
#include <algorithm> 
#include <list>
#include "List.cpp"
using namespace std;

int main(){
	List<int> d;
	d.push_back(5);
	d.push_back(4);
	d.push_back(7);
	d.push_back(9);
	List<int>::Iterrator a(d.begin());
	a++;
	a++;
	++a;
	cout << *a;
	return 0;
}