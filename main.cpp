#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <ctime>

using namespace std;


/*
In this tutorial we cover a programic approach to interpolation. Using C++ and
binary search trees we can quickly create interpolation.

Author: github@lozzoc May 15,2020
License: GPL


if it is in the middle of two values
       0.5
[   1   ,  2 ]
Application of Linear Intepolation
using x1,x2, y1,y2 searchTerm and interpolatedValue
interpolatedValue = (searchTerm - x1) * (y2-y1) / (x2-x1) + y1 /// y = mx+b
return (searchTerm - x1) * (y2-y1) / (x2-x1) + y1

*/

float lookupTable(float * nums,int len, float searchTerm){

  /* First our bounds check, if the
  value is outside the table,
  return the y value from the edge*/

  if(nums[0] >= searchTerm){
    return nums[1];
  }
  else if(nums[len-2] <= searchTerm){
    return nums[len-1];
  }
  else{
    for(int i=0;i<len/2-1;i++){
      if(searchTerm<nums[i*2]){
        double x1=nums[i*2-2], x3 = nums[i*2],y1=nums[i*2-1],y3=nums[i*2+1];
        return (searchTerm - x1) * (y3-y1) / (x3-x1) + y1;
      }
    }
  }
}


/* This table scans the data and performs binary search
to find the closest match, then uses interpolate to return the value;
in this case my table finds the y for the closest matching x.
*/
float lookupTableBST(float * nums,int len, float searchTerm){

  /* First our bounds check, if the
  value is outside the table,
  return the y value from the edge*/

  if(nums[0] >= searchTerm){
    return nums[1];
  }
  else if(nums[len-2] <= searchTerm){
    return nums[len-1];
  }
  else{
    int mid,low=0, high=(len/2)-1;

    while(low <= high){
      mid = (low+high) /2;

      if(nums[2*mid] == searchTerm){
        return nums[2*mid+1];
      }
      /*====================== interpolate extra conditionals
       */
      else if(mid!=0 && nums[2*mid] > searchTerm && nums[2*mid-2] < searchTerm ){
        float x1 = nums[2*mid-2],
              x3 = nums[2*mid];
        float y1 = nums[2*mid-1],
              y3 = nums[2*mid+1];

        return (searchTerm - x1) * (y3-y1) / (x3-x1) + y1;
      }
      else if(mid!=len-2 && nums[2*mid] < searchTerm && nums[2*mid+2] > searchTerm ){
        // x2 = nums[2*mid+2]
        // x1 = nums[2*mid]
        float x1 = nums[2*mid],
              x3 = nums[2*mid+2];
        float y1 = nums[2*mid+1],
              y3 = nums[2*mid+3];
        return (searchTerm - x1) * (y3-y1) / (x3-x1) + y1;
      }
      /*
      basically if the in between value is to the right or left of our current
      Cursor.  ~O(2) check.
      ==========================
      */

      /*here is the bst code that is for a sorted array
      set the left or right bounds to the current middle
      then recalculate the middle*/
      else if(nums[2*mid] < searchTerm){
        low = mid+1;
      }
      else{
        high = mid - 1;
      }

    }

    printf("We should never reach this code\n");
    return -1;


  }

  //return math
}



float rand_FloatRange(float a, float b)
{
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

int main(int argc, char* argv[]){
  int NUM_TRIALS = 0;

  if(argc == 2){
    NUM_TRIALS = atoi(argv[1]);
  }
  else{
    NUM_TRIALS = 10;

  }
  const int ARRAY_SIZE = 500000;
  float * hardcoded = (float *) malloc(sizeof(float)*ARRAY_SIZE*2);
  float * trials = (float * ) malloc(sizeof(float)*NUM_TRIALS);
  float y,xt,yt;

  srand(static_cast<unsigned int>(time(0))); // Seed random number generator


  // always ranges from 0 to 50000,
  for(int i=0;i<ARRAY_SIZE;i++){
    hardcoded[2*i] = 0.1*i;
    hardcoded[2*i+1] = 0.1*i*0.1*i * 0.5;

  }
  for(int i=0;i<NUM_TRIALS;i++){
    trials[i] = rand_FloatRange(1000,5000);
  }

  clock_t start = clock();
  for(int i=0;i<NUM_TRIALS;i++){
    yt = lookupTableBST(hardcoded,ARRAY_SIZE,trials[i]);

    if(NUM_TRIALS<11){
      //this means debug
      printf("Epected:%.2f \t Actul %.2f\n",yt,trials[i]*trials[i]*0.5);
    }
  }
  clock_t end= clock();
  printf("\n%i,%.4f", ARRAY_SIZE,(float)(end - start) * 1000.0 / CLOCKS_PER_SEC);


  delete hardcoded;
  delete trials;
  return 0;
}

/* 12.644 to 69.59
is 16.412 to 103.510
 if we were truly growing log2 then y2 would be 89 and not 103
*/
