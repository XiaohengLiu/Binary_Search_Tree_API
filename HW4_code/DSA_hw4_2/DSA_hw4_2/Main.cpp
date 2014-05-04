#include<iostream>
#include<fstream>
#include"BST.h"
using namespace std;

int main()
{
	BST<int,int> BSTTable;

	ifstream inFile("select_data.txt");
	int number;
	while (inFile>>number)
		BSTTable.insert(number,number);
	
	cout<<"the value of select(7): "<<BSTTable.select(7)<<endl;
	cout<<"the value of rank(7): "<<BSTTable.rank(7)<<endl;
}