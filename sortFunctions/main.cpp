#include<iostream>
#include <fstream>
#include<chrono>
#include<ctime>
#include<cmath>
#include<cstring>
#include "sortFunction.h"

using namespace std; 

enum sortowania{
    BUBBLE,
    BUCKET,
    HEAP,
    INSERTION, 
    MERGE,
    QUICK,
    RADIX,
    SELECTION,
};

string printCoSortuje(int n)
{
    string result = "";
    switch(n){
        case 0: result = "BUBBLE SORT"; break;
        case 1: result = "BUCKET SORT"; break;
        case 2: result = "HEAP SORT"; break;
        case 3: result = "INSERTION SORT"; break;
        case 4: result = "MERGE SORT"; break;
        case 5: result = "QUICK SORT"; break;
        case 6: result = "RADIX SORT"; break;
        case 7: result = "SELECTION SORT"; break;
        default: result = "ANOTHER OPTION SORT"; break;    
    }
    return result;
}

int main(){
    srand (time(NULL));
    int Array[1000]{0};
    int max(255); int min(0);
    static const double fraction = 1.0 / (RAND_MAX + 1.0); 

    for(int i=0;i<1000;i++)
        Array[i] = static_cast<int>((max - min + 1) * (rand() * fraction));
   
    int size = sizeof(Array) / sizeof(Array[0]);
    
//    float Array2[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
//    int size = sizeof(Array2) / sizeof(Array2[0]);
    
    printArray(Array,size);
    
    using ns = chrono::nanoseconds;
    using get_time = chrono::steady_clock;
    
    fstream myfile;

    myfile.open ("result.txt",ios::app);
    myfile << printCoSortuje(7)<< ">-----------------------------------------------"<<endl;
    auto start = get_time::now();
    
//    mergeSort(Array,0,size-1);
//    radixSort(Array,size);
    quickSort(Array,0, size-1);
//    selectionSort(Array, size);
//    insertionSort(Array,size);
//    heapSort(Array,size);
//    bubbleSort(Array,size);
//    bucketSort(Array2, size);    
    
    auto end = get_time::now();
    auto diff = end - start;
    myfile << " : "<< chrono::duration_cast<ns>(diff).count()<<endl;
    myfile << printCoSortuje(5) << "<-----------------------------------------------"<<endl;

    myfile.close();
    
    printArray(Array,size);
    return 0;
}
