int binary_search(int q, int* array, int n) {
  int mid, low = 0, high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (array[mid] == q) {
      return mid;
    } else if (array[mid] < q){
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}
