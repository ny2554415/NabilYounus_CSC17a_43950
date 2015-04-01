/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 16, 2015, 1:09 PM
 * Purpose:  DB Sort
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillAry(int *,int);
void prntAry(int *,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize the array
    //const int SIZE=514250;//Single array
    const int SIZE=257125;//2 Arrays meaning total memory local limited
    int array[SIZE],brray[SIZE];
    fillAry(array,SIZE);
    fillAry(brray,SIZE);
    cout<<array[SIZE-1]<<endl;
    cout<<brray[SIZE-1]<<endl;
    //Exit stage right
    return 0;
}
void prntAry(int *a,int n,int perLine){
    //Loop and print
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int *a,int n){
    //Fill with random 2 digit numbers
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}