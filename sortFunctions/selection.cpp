void swap(int *a,int *b);

void selectionSort(int table[], int size){
    int id;
    for(int i=0;i<size-1;i++){
        id = i;
        for(int j=i+1;j<size;j++){
            if(table[j]<table[id])
                id = j;
        }
        swap(&table[i],&table[id]);
    }
}