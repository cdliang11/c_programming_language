#include <stdio.h>

int binsearch(int x, int v[], int n) {
	int low = 0, high = n - 1, mid; 
	
	while (low < high) {
		mid = (low + high) / 2;
		// 相比于原始减少了一次判断 
		printf("%d,%d,%d\n", v[low], v[high], v[mid]); 
		if (x <= v[mid]) {
			high = mid;
		}
		else {
			low = mid+1;
		}
	} 
	return v[low] == x ? low : -1;
}

int main() {
	int x = -1;
	int v[8] = {0,1,2,3,4,5,6,7};
	int n = 8;
	printf("%d", binsearch(x, v, n));
	return 0;
}
