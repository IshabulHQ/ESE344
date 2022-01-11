#include <iostream>
using namespace std;
#include <iostream>
#include <fstream>
// Write and run a C++ test program that reads 10 floating
// point numbers from the console and prints their minimum,
// maximum, mean, and standard deviation to the console.


float calculateMin(float input[], int length){

    float min = input[0];
    for(int i = 1; i < length; i++){
        if(min > input[i]){
            min = input[i];
        }

    }

    return min;
}

float calculateMax(float input[],int length){


    float max = input[0];
    for(int i = 1; i < length; i++){
        if(max < input[i]){
            max = input[i];
        }

    }

    return max;

}
float calculateMean(float input[],int length){

    float sum = 0.0;
    for(int i = 0; i < length; i++) {
        sum += input[i];

    }
    float mean = sum / 10.0;
    return mean;
}

float calculateSTD(float input[], float mean,int length){
    float std = 0.0;

    for(int i = 0; i < length; i++){
        std += pow(input[i] - mean,2);
    }

    std = sqrt(std/10);
    return std;

}


int main() {
    int length = 10;

    float numbers[length];

    // Get input from command line

//    cout << "Enter 10 numbers";
//    for (int i = 0; i < length; i++) {
//        cin >> numbers[i];
//    }

    // Get input from outside text file
    cout << "Reading 10 numbers from file" << endl;
    string filename("input.txt");
    float number;
    int i = 0;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file >> number) {
        numbers[i] = number;
        i++;
    }

    input_file.close();


    float min = calculateMin(numbers, length);
    float max = calculateMax(numbers, length);
    float mean = calculateMean(numbers, length);
    float std = calculateSTD(numbers, mean, length);

    cout << "Minimum Number: " << min << endl;
    cout << "Maximum Number: " << max << endl;
    cout << "Mean: " << mean << endl;
    cout << "Standard Deviation: " << std << endl;
}