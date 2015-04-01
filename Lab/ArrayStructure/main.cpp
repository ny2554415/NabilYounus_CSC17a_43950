/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 25, 2015, 12:53 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Library
#include "Array.h"

//Global Constants

//Function Prototypes
Array *flArray(int);
void   prntAry(const Array *,int);
void   destroy(Array *);
void   copy(Array &,const Array *);

//Execution begins here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    Array *vec=flArray(100);
    cout<<"This is a bad copy"<<endl;
    Array vec1=*vec;
    //Print the array
    cout<<"Show the orginal with the bad copy"<<endl;
    prntAry(vec,10);
    prntAry(&vec1,10);
    //Show the data is the same but not the size
    vec1.data[0]=0;
    vec1.size=50;
    cout<<"Change the copy and it changes the original data"<<endl;
    cout<<"but not the size"<<endl;
    prntAry(vec,10);
    prntAry(&vec1,10);
    //Perform a proper copy
    cout<<"Make a proper copy"<<endl;
    Array vec2;
    copy(vec2,vec);
    vec2.data[0]=100;
    cout<<"Copy changed the orginal remains the same"<<endl;
    prntAry(vec,10);
    prntAry(&vec2,10);
    //Destroy the array and exit stage right
    destroy(vec);
    return 0;
}

void   copy(Array &b,const Array *a){
    //Perform the copy
    b.size=a->size;
    for(int i=0;i<a->size;i++){
        b.data[i]=a->data[i];
    }
}

void   destroy(Array *array){
    delete []array->data;
    delete array;
}

void   prntAry(const Array *array,int perLine){
    cout<<endl;
    //Print the array
    for(int i=0;i<array->size;i++){
        //cout<<array->data[i]<<" ";
        //cout<<(*array).data[i]<<" ";
        cout<<*((*array).data+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    //Exit stage right!
    cout<<endl;
}

Array *flArray(int n){
    //Create a pointer to the structure
    Array *array=new Array;
    //Allocate memory for the array
    array->data=new int[n];
    array->size=n;
    //Fill the array with 2 digits integers
    for(int i=0;i<array->size;i++){
        array->data[i]=rand()%90+10;
    }
    //Exit stage right!
    return array;
}