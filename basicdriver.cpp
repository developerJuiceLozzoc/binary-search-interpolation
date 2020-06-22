
#include <stdio.h>
#include "LinearInterpolateBST.cpp"

#define len 7
int main(){

  float nums[len*2];
  for(int i=0;i<len*2-1;i+=2){
   nums[i] = i;
   nums[i+1]=(i)*(i);
   printf("%1.0f, %1.0f, ",nums[i],nums[i+1]);
  }
  printf("\n");

  printf("Can it return the value? -1: %.2f\n", InterpolateYGivenXBST(nums,len,-1.0));
  printf("Can it return the value? 0.5: %.2f\n", InterpolateYGivenXBST(nums,len,0.5));
  printf("Can it return the value? 2: %.2f\n", InterpolateYGivenXBST(nums,len,2.0));
  printf("Can it return the value? 3: %.2f\n", InterpolateYGivenXBST(nums,len,3));
  printf("Can it return the value? 4: %.2f\n", InterpolateYGivenXBST(nums,len,4));

  printf("Can it return the value? 10: %.2f\n", InterpolateYGivenXBST(nums,len,10));
  printf("Can it return the value? 50: %.2f\n", InterpolateYGivenXBST(nums,len,50));




}
