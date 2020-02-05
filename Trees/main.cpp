#include <iostream>
#include "Tree.h"
#include "Avltree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <windows.h>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <stdexcept>
#include <fstream>

using namespace std;


void creArray(int* arr, int siz)
{
    LARGE_INTEGER seed;
    QueryPerformanceCounter(&seed);
    std::mt19937 gen(seed.QuadPart);

    std::uniform_int_distribution<> dis(-2*siz, 2*siz);

    for (int i=0; i < siz; i++)
        arr[i]=dis(gen);
}


void CreaNew (int *A, int *B, int siz)
{
    LARGE_INTEGER seed;
    QueryPerformanceCounter(&seed);
    std::mt19937 gen(seed.QuadPart);

    std::uniform_int_distribution<> dis(-6*siz, 6*siz);

    for (int i=0; i < siz; i++)
    {
        B[i]=dis(gen);
        i++;
        B[i]=A[i];
    }

}


void cop (int *A, int *B, int siz)
{
    for (int i=0; i < siz; i++)
    {
        B[i]=A[i];
    }

}


int main()
{
    ofstream myfile;
LARGE_INTEGER li;
QueryPerformanceFrequency(&li);
double PCFreq = li.QuadPart/1000.0;
int64_t startt;
int64_t endd;

int times = 1;

int k=10;
/*
myfile.open ("Trees.txt" , ios::app );
myfile <<"Elements \t\t insertion BST: "<< "\t insertion AVL : "   << "\t  search BST: "<< "\t\t search AVL : "   << endl ;
myfile.close();

*/

for (size_t siz = 10; siz<10000000; )
{

    int *A = new int[siz];
    int *BSTsear = new int[siz];
    int *AVLsear = new int[siz];
    double SimpleTree =0;
    double AVL =0;
        double BSTs =0;
    double AVLs =0;
    vector<int> BSTfound;
    vector<int> AVLfound;
    /*
myfile.open ("Trees.txt" , ios::app );
myfile  << siz << "\t\t\t";
myfile.close();
*/
for (int k=0; k<times; k++)
    {
    creArray(A,siz);
    CreaNew(A,BSTsear, siz);
    cop(BSTsear,AVLsear, siz);

       tree x;
        tree1 y;

// insert in BST
QueryPerformanceCounter(&li);
startt = li.QuadPart;
for(int i=0;i<siz;i++)
    x.push(A[i]);
QueryPerformanceCounter(&li);
endd = li.QuadPart;
SimpleTree = endd - startt + SimpleTree;

// insert in AVL
    QueryPerformanceCounter(&li);
startt = li.QuadPart;
 for(int i=0;i<siz;i++)
    y.push(A[i]);
QueryPerformanceCounter(&li);
endd = li.QuadPart;
AVL = endd - startt + AVL;


// search in BST
int kkk = x.nelems();
QueryPerformanceCounter(&li);
startt = li.QuadPart;
for(int i=0;i<kkk;i++)
    if(x.sear(BSTsear[i]))
        BSTfound.push_back(BSTsear[i]);
QueryPerformanceCounter(&li);
endd = li.QuadPart;
BSTs = endd - startt + BSTs;

 //      cout << BSTfound.size() << "is found BST";

int zzz = y.nelems();
    QueryPerformanceCounter(&li);
startt = li.QuadPart;
for(int i=0;i<zzz;i++)
    if(y.sear(AVLsear[i]))
        AVLfound.push_back(AVLsear[i]);
QueryPerformanceCounter(&li);
endd = li.QuadPart;
AVLs = endd - startt + AVLs;


 //      cout << AVLfound.size() << "is found AVL";

 // cout << "Number of elements is " << siz << " but in tree " << x.nelems() << endl;   functions nelems to check how many elements in tree.
    }

cout  <<  setw(8) << fixed <<"For " << siz <<" elements: \n time wasted on insertion BST: " << SimpleTree/PCFreq/times << endl
  << " time wasted on insertion AVL : " << AVL/PCFreq/times << endl  << " time wasted on search BST: " << BSTs/PCFreq/times << endl
  << " time wasted on search AVL : " << AVLs/PCFreq/times << endl ;



/*
  myfile.open ("Trees.txt" , ios::app );
myfile  <<  setw(8) << fixed  << SimpleTree/PCFreq/times  << "\t\t  " << AVL/PCFreq/times  << "\t\t  " << BSTs/PCFreq/times  << "\t\t " << AVLs/PCFreq/times << endl ;
myfile.close();
*/
        siz=siz+k;
        if(siz==k*6)
        {
        k=k*10;
        siz=1*k;
        }
}
    return 0;
}
