void swap(int *a,int *b);

void heapify(int Array[],int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l < n && Array[l] > Array[largest])
        largest = l;
    if(r < n && Array[r] > Array[largest])
        largest = r;
    
    if(largest != i){
        swap(&Array[i],&Array[largest]);
        heapify(Array,n,largest);
    }
}

void heapSort(int Array[],int size){
    for(int i=size/2 -1;i>=0;i--){
        heapify(Array,size,i);
    }
    
    for(int i=size-1;i>=0;i--){
        swap(&Array[0],&Array[i]);
        heapify(Array,i,0);
    }
}