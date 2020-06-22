
#include <stdio.h>
#include "LinearInterpolateBST.cpp"

int main(){

  float nums[14]= {1.0,2 , 2.0,4,3,8 ,4,16 ,5,32 , 6,64, 7,128};

  printf("Can it return the value? 4: %.2f\n", InterpolateYGivenXBST(nums,7,4.5));
  printf("Can it return the value? 6.5: %.2f\n", InterpolateYGivenXBST(nums,7,6.5));
  printf("Can it return the value? 7.5: %.2f\n", InterpolateYGivenXBST(nums,7,7.5));





}
