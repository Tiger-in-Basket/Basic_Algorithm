#include <iostream>
#include <stdlib.h>
using namespace std;

void Quick_Sort(int *nums, int begin_point, int end_point){
	int left_ptr = begin_point;
	int right_ptr = end_point;
	int base = nums[begin_point];
	int temp = 0; 

	if (end_point <= begin_point){
		return;
	}
	while (left_ptr < right_ptr){
		while (left_ptr < right_ptr && nums[right_ptr] >= base){
			right_ptr--;
		}

		while (left_ptr < right_ptr && nums[left_ptr] <= base){
			left_ptr++;
		}

		if (left_ptr < right_ptr){
			temp = nums[left_ptr];
			nums[left_ptr] = nums[right_ptr];
			nums[right_ptr] = temp;
		}else{
			temp = nums[left_ptr];
			nums[left_ptr] = base;
			nums[begin_point] = temp;
		}
	}

	Quick_Sort(nums, left_ptr + 1, end_point);
	Quick_Sort(nums, 0, left_ptr - 1);

}


int main(){

	int *nums = NULL;
	
	nums = (int *)malloc(sizeof(int));
	
	int num, i = 0;

	cout << "please enter some numbers seperated by space," << endl;
	cout << "if you have finished, please start a new line and print 'done'" << endl;
	while (cin >> num) {
		nums = (int *)realloc(nums, (i+1)*sizeof(int));
		*(nums + i) = num;
				
		i += 1;		 
	}

	Quick_Sort(nums, 0, i-1);
	for (int a = 0; a < i; a++){
		cout << nums[a] << " ";
	}
	cout << endl;
}