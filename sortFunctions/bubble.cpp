void swap(int *a,int *b);

void bubbleSort(int Array[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++)
            if(Array[j+1]<Array[j])
                swap(&Array[j],&Array[j+1]);
    }
}