#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for sqrt()
#include <vector>
using namespace std;
#define MAX 5000
#define randMax 10000
int counterQ = 0;
int counterH = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Start of Quick Sort Algorithm

vector<int> partition(vector<int> &v, int left, int right) {

    int middle = left;

    vector<int> sorted(2);
    while(middle <= right) {
        counterQ++;
        if(v[middle] < v[left])  {
            swap(v[middle], v[left]);
            ++left;
            ++middle;
        }

        else if(v[middle] == v[left]) {
            counterQ++;
            ++middle;
        }
        else {
            counterQ++;
            swap(v[right], v[middle]);
            --right;
        }
    }

    sorted[0] = left;
    sorted[1] = middle;

    return sorted;
}


void quick_sort(vector<int> &v, int left, int right, int &counterQ) {


    if (left >= right) {
        return;
    }

    //Random pivot
    int p = left + rand() % (right - left + 1);
    //place the pivot in the first index
    swap(v[left], v[p]);

    vector<int> v2 = partition(v, left, right);
    //Sort the first half of the vector
    quick_sort(v, left, v2[0],counterQ );
    //Sort the second half of the vector
    quick_sort(v, v2[1], right,counterQ);
}
// End of Quick Sort Algorithm

// Start of Heap Sort Algorithm
void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    counterH++;
    if (l < n && v[l] > v[largest])
        largest = l;


    counterH++;
    if (r < n && v[r] > v[largest])
        largest = r;


    counterH++;
    if (largest != i) {
        swap(v[i], v[largest]);


        heapify(v, n, largest);
    }
}


void heapSort(vector<int> &v, int n, int &counterH)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--) {

        heapify(v, n, i);
    }

    // Extract  element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(v[0], v[i]);


        heapify(v, i, 0);
    }
}

// End of Heap Sort Algorithm



// Print Array in formatted manner
void printList(vector <int> v, int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int minCalc(int array[]){

    int min = array[0];
    for(int i = 1; i < sizeof(array); i++){
        if(array[i] < min)
            min = array[i];

    }

    return min;
}

int maxCalc(int array[]){

    int max = array[0];
    for(int i = 1; i < sizeof(array); i++){
        if(array[i] > max)
            max = array[i];

    }

    return max;
}

int medianCalc(int array[]){
    return array[sizeof(array)/2];
}

double meanCalc(int array[]){
    double size = sizeof(array);
    double sum = 0.0;

    for(int i = 0; i < size; i++){
        sum+= array[i];
    }

    return sum/size;
}

double sTDCalc(int array[], double mean){

    double sum = 0.0;
    int size = sizeof(array);
    double variance = 0.0;
    for(int i = 0; i < size; i++){
        variance += pow(array[i] - mean,2);
    }
    variance = variance / (double)size;
    double sTD = sqrt(variance);

    return sTD;



}


int main() {


    int QScomparisons [30];
    int HScomparisons [30];
    int r;
    srand((unsigned int) time(0));// seed rand() with system time
    vector<int> v(MAX);
    vector<int> v2(MAX);
    for(int i = 0; i < 30; i++){


        // Generating Random Numbers
        if(i == 0)
            cout << "Generating 5,000 Random Numbers..." << endl;
        for (int & j : v) {
            r = rand() % randMax;
            j = r;
        }


        v2 = v;
        //cout << "Unsorted List: " << endl;
        //printList(v,v.size());
        if(i == 0)
            cout << "Sorting Set of Random Numbers using Quick Sort..." << endl;
        quick_sort(v, 0, v.size() - 1,counterQ); //sort the elements of array
        //printf("List Sorted with Quick Sort: \n");
        //(v, v.size() - 1);
        //cout << "Number of comparisons: " << counterQ << endl;

        if( i == 0)
            cout << "Sorting Identical Set of Random Numbers Using Heap Sort..." << endl;

        heapSort(v2,v2.size(),counterH);
        //printf("List Sorted with Heap Sort: \n");
        //printList(v2,v2.size());
        //cout << "Number of comparisons: " << counterH << endl;
        QScomparisons[i] = counterQ;
        HScomparisons[i] = counterH;
       // cout << counterQ << endl;
        counterH = 0;
        counterQ = 0;
        //v.clear();
        //v2.clear();

        if(i == 0)
            cout << "Repeating Process 29 more times..." << endl;

    }

    int QSmin = minCalc(QScomparisons);
    int HSmin = minCalc(HScomparisons);
    int QSmax = maxCalc(QScomparisons);
    int HSmax = maxCalc(HScomparisons);
    int QSmedian = medianCalc(QScomparisons);
    int HSmedian = medianCalc(HScomparisons);
    double QSmean = meanCalc(QScomparisons);
    double HSmean = meanCalc(HScomparisons);
    double QSSTD = sTDCalc(QScomparisons,QSmean);
    double HSSTD = sTDCalc(HScomparisons,HSmean);

    cout << "Generating Statistics for Quick Sort Comparisons... \n" << endl;
    cout << "Full Set of Comparisons Made with Quick Sort: " << endl;
    for (int i=0; i < 30; i++)
        printf("%d ", QScomparisons[i]);
    printf("\n");
    cout <<"\nMinimum: " << QSmin << endl;
    cout <<"Maximum: " << QSmax << endl;
    cout <<"Median: " << QSmedian << endl;
    cout <<"Mean: " << QSmean << endl;
    cout <<"Standard Deviation: " << QSSTD << endl;

    cout << "\nGenerating Statistics for Heap Sort Comparisons..." << endl;
    cout << "Full Set of Comparisons Made with Quick Sort: " << endl;
    for (int i=0; i < 30; i++)
        printf("%d ", HScomparisons[i]);
    printf("\n");
    cout <<"\nMinimum: " << HSmin << endl;
    cout <<"Maximum: " << HSmax << endl;
    cout <<"Median: " << HSmedian << endl;
    cout <<"Mean: " << HSmean << endl;
    cout <<"Standard Deviation: " << HSSTD << endl;

//    v2 = v;
//    cout << v.size() << endl;

}