#include<stdio.h>
#include<stdlib.h>


int merge_sort(int *number, int left, int right){
	if (left == right)
		return 0;


	int left_first, right_first, sort_first;
	int mid = (left + right) / 2;

	left_first = left;
	right_first = mid + 1;
	sort_first = 0;


	merge_sort(number, left, mid);
	merge_sort(number, mid + 1, right);

	int *sort_number = (int *)malloc(sizeof(int) * right - left + 1);


	while (sort_first != right && left_first != mid + 1 && right_first != right + 1){


		if (number[left_first] >= number[right_first]){
			sort_number[sort_first] = number[right_first];
			right_first++;
			sort_first++;
		}

		else{
			sort_number[sort_first] = number[left_first];
			left_first++;
			sort_first++;
		}


	}

	if (left_first != mid + 1){
		while (left_first != mid + 1){
			sort_number[sort_first] = number[left_first];
			sort_first++;
			left_first++;
		}

	}

	else if (right_first != right + 1){
		while (right_first != right + 1){
			sort_number[sort_first] = number[right_first];
			sort_first++;
			right_first++;
		}

	}


	sort_first = 0;
	for (int i = left; i <= right; i++){
		number[i] = sort_number[sort_first];
		sort_first++;

	}

	free(sort_number);

	return 0;


}



int main(){
	int left = 0;
	int count;

	scanf("%d", &count);

	int *number = (int *)malloc(sizeof(int) *count);


	for (int i = 0; i<count; i++)
		scanf("%d", number + i);



	merge_sort(number, left, count - 1);


	for (int i = 0; i<count; i++)
		printf("%d\n", number[i]);

	free(number);




}