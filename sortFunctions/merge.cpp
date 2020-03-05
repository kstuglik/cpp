void swap(int *a,int *b);

void merge(int Array[],int l,int m, int r){
    int sizeL=m-l+1;
    int sizeR=r-m;
    
    int leftA[sizeL];
    int rightA[sizeR];
    
    for(int i=0;i<sizeL;i++){
        leftA[i] = Array[l+i];
    }
        
    for(int i=0;i<sizeR;i++){
        rightA[i] = Array[m+i+1];
    }
    
    int i,j,k;
    i=j=0;
    k=l;
    
    while(i<sizeL && j<sizeR){
        if(leftA[i]<=rightA[j]){
            Array[k] = leftA[i];
            i++;
        }
        else{
            Array[k] = rightA[j];
            j++;
        }
        k++;
    }
    

    while(i<sizeL){
        Array[k] = leftA[i];
        k++;i++;
    }
 
    while(j<sizeR){
        Array[k] = rightA[j];
        k++;j++;
    }   
}

void mergeSort(int Array[],int l,int r){
    if(l<r){
        int m = (r-l)/2 + l;
        
        mergeSort(Array,l,m);
        mergeSort(Array,m+1,r);
        
        merge(Array,l,m,r);
    }
}
