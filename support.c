//sắp xếp
void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int tmp = i;
        for(int j = i; j < n; j++){
            if(a[tmp] < a[j]){
                tmp = j;
            }
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}