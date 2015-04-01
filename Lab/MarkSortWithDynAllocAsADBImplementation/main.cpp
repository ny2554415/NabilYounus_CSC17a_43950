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
int *fillAry(int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
int *mrkSort(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize the array
    int size=100;
    int *array=fillAry(size);
    //Print the array
    cout<<"The original array before sorting"<<endl;
    prntAry(array,size,10);
    //Sort the array
    int *indx=mrkSort(array,size);
    //Print the original and then the sorted array
    cout<<"The original array after sorting"<<endl;
    prntAry(array,size,10);
    cout<<"The indexed array after sorting"<<endl;
    prntAry(indx,size,10);
    cout<<"The original array with the sorted index"<<endl;
    prntAry(array,indx,size,10);
    //Deallocate memory
    delete []array;
    delete []indx;
    return 0;
}

int *mrkSort(int *a,int n){
    //Allocate the indexed array
    int *indx=new int[n];
    //Initialize the index
    for(int i=0;i<n;i++){
        indx[i]=i;
    }
    //Sort the array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[indx[i]]>a[indx[j]]){
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    return indx;
}

void prntAry(int *a,int *indx,int n,int perLine){
    //Loop and print
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
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

int *fillAry(int n){
    //Declare and allocate the array
    int *a=new int[n];
    //Fill with random 2 digit numbers
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    //Exit
    return a;
}