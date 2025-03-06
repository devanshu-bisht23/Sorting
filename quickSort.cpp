#include <iostream>
#include <vector>

using namespace std;

void swap(int &i, int &j){  
    int temp = i;
    i = j;
    j = temp;
}

int partition(vector<int> &arr, int l, int r){ // for finding that one element that is sorted



    int pivot = arr[r];  
    int i = l - 1;

    for(int j = l; j<r; j++){

        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1],arr[r]); // i + 1 cuz we have to put our pivot at next index after i 

    return (i+1); // return the index of that perfectly placed element

}


void quickSort(vector<int> &arr, int l, int r)
{

    if (l < r)
    {
        int p = partition(arr, l , r);
        quickSort(arr, l, p-1); // sort left
        quickSort(arr, p+1, r); // sort right
    }
}

int main()
{

    cout << "Enter size of arr: ";
    int n;
    cin >> n;
    vector<int> arr;
    cout << "Enter arr elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp); 
    }
    int l = 0, r = n - 1; 
    quickSort(arr, l, r);

    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
