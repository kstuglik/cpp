#ifndef SORTFUNCTION_H
#define SORTFUNCTION_H

void quickSort(int Array[],int low, int high);
void selectionSort(int table[], int size);
void radixSort(int Array[],int size);
void mergeSort(int Array[],int l,int r);
void insertionSort(int Array[],int size);
void heapSort(int Array[], int n);
void bucketSort(float Array[], int n);
void bubbleSort(int Array[],int size);

void printArray(int Array[],int size);
void printArray(float Array[],int size);

#endif