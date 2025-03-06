#include <iostream>
#include <vector>
#include<cstdlib> // for rand
#include <ctime> // for seed to generate random number

using namespace std;

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

int partition(vector<int> &arr, int l, int r)
{
    // for random 
    
    int x = l + rand() % (r - l + 1); // choose a random element's index
    swap(arr[x], arr[r]); //swap the random element with last element

    int pivot = arr[r];
    int i = l-1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {

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
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    srand(time(0));
    
    cout << "enter n:";
    int n;
    cin >> n;
    vector<int> arr;
    cout << "enter array elements:";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    int l = 0, r = n - 1;

    // cout << r;

    quickSort(arr, l, r);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}