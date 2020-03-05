void swap(int *a,int *b);

int partition(int Array[],int low, int high){
    int pivot = Array[high];
    int i = low - 1,j;
    for(j=low; j<high;j++){
        if(Array[j] <= pivot){
            i++;
            swap(&Array[i],&Array[j]);
        }
    }
    swap(&Array[i+1],&Array[high]);
    return i+1;
}

void quickSort(int Array[],int low, int high){
    if(low<high){
        int pivot = partition(Array,low,high);
        
        quickSort(Array,low,pivot-1);
        quickSort(Array,pivot+1,high);
    }
}