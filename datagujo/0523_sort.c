#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SZ 5

int main() {

	int num[] = { 5,4,3,2,1 };
	// bubble
	//for (int j = 0; j < SZ - 1; j++) {
	//	for (int i = 0; i < SZ - 1 - j; i++) {
	//		if (num[i] > num[i + 1]) {
	//			int temp = num[i];
	//			num[i] = num[i + 1];
	//			num[i + 1] = temp;
	//		}
	//	}
	//}

	// selection
	//for (int j = 0; j < SZ - 1; j++) {
	//	int sidx = j;
	//	for (int i = j; i < SZ; i++) {
	//		if (num[i] < num[sidx]) {
	//			sidx = i;
	//		}
	//	}
	//	int temp = num[j];
	//	num[j] = num[sidx];
	//	num[sidx] = temp;
	//}

	// insertion
	//for (int j = 0; j < SZ - 1; j++) {
	//	for (int i = j + 1; i > 0; i--) {
	//		if (num[i] < num[i - 1]) {
	//			int temp = num[i];
	//			num[i] = num[i - 1];
	//			num[i - 1] = temp;
	//		}
	//		else {
	//			break;
	//		}
	//	}
	//}



	for (int i = 0; i < SZ; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}