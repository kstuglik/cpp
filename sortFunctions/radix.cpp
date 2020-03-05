int getMax(int Array[],int size){
    int x = Array[0];
    for(int i=0;i<size;i++){
        if(Array[i]>x){
            x = Array[i];
        }
    }
    return x;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int Array[],int size){
    int k = getMax(Array,size);
    for(int exp=1;k/exp>0;exp*=10){
        countSort(Array,size,exp);
    }
}