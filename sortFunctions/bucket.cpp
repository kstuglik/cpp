#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void swap(int *a,int *b);

void bucketSort(float Array[], int n)
{
    vector<float> b[n];
    for (int i=0; i<n; i++)
    {
       int bi = n*Array[i]; // Index in bucket
       b[bi].push_back(Array[i]);
    }
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          Array[index++] = b[i][j];
}