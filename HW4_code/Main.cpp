#include<iostream>
#include<string>
#include<ctime>
#include<set>
#include<vector>
#include<algorithm>
#include"Node.h"
#include"ST.h"

using namespace std;
const int Num = 10000;//the number of random number to be generated
void dfs(Node<int,int>* pNode,int &nop,int spl,int &tpl);//depth first search
int main()
{
	ST<int,int> RBTable_r;//for random insertions
	ST<int,int> RBTable_s;//for sorted insertoins

	//number of paths, total path length, single path length
	int numOfPath_r = 0;
	int numOfPath_s = 0;
	int totalPathLength_r = 0;
	int totalPathLength_s = 0;
	int singlePathLength_r = 0;
	int singlePathLength_s = 0;
	
	//generate different random keys
	set<int> setKey;
	srand(time(NULL));
	int randNum;
	while (setKey.size() < Num)
	{
		randNum = rand();
		setKey.insert(randNum);
	}

	//two vectors: one for sorted number, one for random number
	vector<int> vec_s;
	for ( set<int>::iterator iter = setKey.begin(); iter != setKey.end(); iter++)
		vec_s.push_back(*iter);
	vector<int> vec_r(vec_s);
	random_shuffle(vec_r.begin(),vec_r.end());

	//insert item into table
	for (vector<int>::iterator iter = vec_s.begin(); iter != vec_s.end(); iter++)
		RBTable_s.insert(*iter,*iter);
	for (vector<int>::iterator iter = vec_r.begin(); iter != vec_r.end(); iter++)
		RBTable_r.insert(*iter,*iter);
		
	cout<<"number of nodes: "<<setKey.size()<<endl<<endl;

	cout<<"after random insertions: "<<endl;
	//RBTable_r.size();
	dfs(RBTable_r.getHead(),numOfPath_r,singlePathLength_r,totalPathLength_r);
	cout<<"number of paths: "<<numOfPath_r<<endl<<"total path length: "<<totalPathLength_r<<endl;
	cout<<"average path length: "<<static_cast<double>(totalPathLength_r)/numOfPath_r<<endl;

	cout<<endl;

	cout<<"after sorted insertions"<<endl;
	//RBTable_s.size();
	dfs(RBTable_s.getHead(),numOfPath_s,singlePathLength_s,totalPathLength_s);
	cout<<"number of paths: "<<numOfPath_s<<endl<<"total path length: "<<totalPathLength_s<<endl;
	cout<<"average path length: "<<static_cast<double>(totalPathLength_s)/numOfPath_s<<endl;
}

void dfs(Node<int,int>* pNode,int &nop,int spl,int &tpl)
{
	if (pNode->p_lNext == NULL && pNode->p_rNext == NULL)
	{
		nop++;
		tpl += spl;
	}
	if (pNode->p_lNext != NULL)
	{
		dfs(pNode->p_lNext,nop,spl+1,tpl);
	}
	if (pNode->p_rNext != NULL)
	{
		dfs(pNode->p_rNext,nop,spl+1,tpl);
	}
}