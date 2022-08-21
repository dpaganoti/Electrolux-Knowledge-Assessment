/*Question 3 - Electrolux Knowledge Assessment. Author: Denner Paganoti - August, 20, 2022*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int arrayLimitSize = 20;
const int arrayUpperValue= 100;
void arraySort(int* arrayManipulated, int beg, int end);
double averageCalculation(int* arrayManipulated, int arraySize);
int arrayEvenSizeCalculation(int* arrayManipulated, int arraySize);
void arrayEvenCalculation(int* arrayManipulated, int* arrayEven, int arraySize, int arrayEvenSize);

int main (){
    
    int i;
    int arraySize;
    double average=0;
    int arrayEvenSize=0;
    int *arrayManipulated;
    int *arrayOriginal;
    int *arrayEven;

    /*To generate the randomic target array to be manipulated, two constants has been used: arrayLimitSize, which determines the maximum size of the array, and arrayUpperValue, which
    determines the greatest value that could be contained in the array. Their values are 20 and 100, respectively. But, this two values can be changed without any other futher problem.
    The block bellow initiates two arrays with the same values. The arrayOriginal contains the values generated randomily. The arrayManipulated is a copy of arrayOriginal, but it's going
    to be sorted in ascending order, to get the maximum and minimum values*/
    srand(time(NULL));
    arraySize=2+rand()%arrayLimitSize;
    arrayManipulated=malloc(arraySize*sizeof(int));
    arrayOriginal=malloc(arraySize*sizeof(int));
    for(i=0;i<arraySize;i++){
        *(arrayManipulated+i)=rand()%arrayUpperValue;
        *(arrayOriginal+i)=*(arrayManipulated+i);
    }

    /*This block sorts the array in ascending order through the arraySort function, in order to get the minimum and maximum values. It also calculates the values' average and generate
    the even values array. More details will be presented in the functions scope bellow*/
    arraySort(arrayManipulated,0,arraySize-1);
    average=averageCalculation(arrayManipulated,arraySize);
    arrayEvenSize=arrayEvenSizeCalculation(arrayManipulated,arraySize);
    if(arrayEvenSize>0){
        arrayEven=malloc(arrayEvenSize*sizeof(int));
        arrayEvenCalculation(arrayManipulated,arrayEven,arraySize,arrayEvenSize);
    }
    
    /*Here the results are presented.*/
    printf("The array has %d numbers. It is formed as follows: \n",arraySize);
    for(i=0;i<arraySize;i++){
        printf("%d\t", arrayOriginal[i]);
    }
    printf("\n\nThe average value of this arrays is %.2f. The greatest value is %d and the smallest is %d.", average, arrayManipulated[arraySize-1],arrayManipulated[0]);
    if(arrayEvenSize>0){
        if(arrayEvenSize==1){
            printf("\n\nThere is just one even number in this array. It's %d.", arrayEven[0]);
        }
        else{
            printf("\n\nThere are %d even numbers in this array. They are:\n", arrayEvenSize);
            for(i=0;i<arrayEvenSize;i++){
                printf("%d\t", arrayEven[i]);
            }
        }
    }
    else{
        ("\n\nThere isn't any even numbers in this array.");
    }

    free(arrayManipulated);
    free(arrayOriginal);
    free(arrayEven);
    return 0;    
}

void arraySort(int* arrayManipulated, int beg, int end){
    
    /*This function sorts the randomic array in ascending order. It's necessary to get the maximum and minimum values. The algorithm used to sort that was the quick sort one.
    This one has been choose due its easy implementation and great perfomance in machine resources consumption.*/
    int left=beg;
    int right=end;
    int pivot=arrayManipulated[(left+right)/2];
    int aux;
    
    while(left<=right){
        while(arrayManipulated[left]<pivot && left<end){
            left++;
        }
        while(arrayManipulated[right]>pivot && right>beg){
            right--;
        }
        if(left<=right){
            aux=arrayManipulated[left];
            arrayManipulated[left]=arrayManipulated[right];
            arrayManipulated[right]=aux;
            left++;
            right--;
        }
    }
    if(right>beg){
        arraySort(arrayManipulated,beg,right);
    }
    if(left<end){
        arraySort(arrayManipulated,left,end);
    }    
}

double averageCalculation(int* arrayManipulated, int arraySize){
    
    /*This function calculates the average of the values from the arrayManipulated. The arrayOriginal could de used as well, since its a copy of the first one, but not sorted in the
    ascending way*/
    int sum=0;
    int i;
    
    for(i=0;i<arraySize;i++){
        sum=sum+(arrayManipulated[i]);
    }    
    return sum/arraySize;
}

int arrayEvenSizeCalculation(int* arrayManipulated, int arraySize){
    
    /*This function maps the number of even numbers in the array and returns their count to allocate the pointer which will receive the even values from the arrayManipulated.*/
    int i;
    int totalEvenNumbers=0;

    for(i=0;i<arraySize;i++){
        if((arrayManipulated[i]%2)==0){
            totalEvenNumbers++;
        }
    }
    return totalEvenNumbers;
}
void arrayEvenCalculation(int* arrayManipulated, int* arrayEven, int arraySize, int arrayEvenSize){

    /*This function fills the arrayEven with the even values extracted from the arrayManipulated*/
    int aux=0;
    int i;
   
    for(i=0;i<arraySize;i++){
        if((arrayManipulated[i]%2==0) && (aux<arrayEvenSize)){
            arrayEven[aux]=arrayManipulated[i];
            aux++;
        }
    }    
}