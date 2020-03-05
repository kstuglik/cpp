void swap(int *a,int *b);

void insertionSort(int Array[],int size){
    for(int i=1;i<size;i++){
        for(int ii=0;ii<=i;ii++){
            if(Array[i]<Array[ii])
                swap(&Array[i],&Array[ii]);
        }
    }
}