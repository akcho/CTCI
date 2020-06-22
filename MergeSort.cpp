#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
}

void Merge(vector<int>& v, vector<int>& helper, int low, int middle, int high) {
    for (int i = low; i <= high; i++) helper[i] = v[i];    // copy v into helper

    int helper_left = low;
    int helper_right = middle + 1;
    int current = low;

    while (helper_left < middle && helper_right < high) {
        if (helper[helper_left] <= helper[helper_right]) {
            v[current] = helper[helper_left];
            helper_left++;
        } else {
            v[current] = helper[helper_right];
            helper_right++;
        }
        current++;
    }

}

void MergeSort(vector<int>& v, vector<int>& helper, int low, int high) {
    if (low < high) {
        int middle = low + ((high - low) / 2);
        cout << "hm";
        MergeSort(v, helper, low, middle);
        MergeSort(v, helper, middle, high);
        Merge(v, helper, low, middle, high);
    }

}

void MergeSort(vector<int>& v) {
    vector<int> helper;
    MergeSort(v, helper, 0, v.size() - 1);
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(8);

    MergeSort(v);
//    PrintVector(v);


    return 0;
}