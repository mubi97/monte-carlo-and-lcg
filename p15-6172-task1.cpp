#include <iostream>

#include <vector>
using namespace std;
double error(int rep[],  int iterations, int size){
	
	double total_error = 0;
	for(int i = 0; i < 100; i++ ){
		double prob = rep[i]/iterations;
		if(prob)
			total_error += (prob - 0.01);
	}
	return total_error/size;
}

void initialize(int arr[], int size){
	for(int i = 0; i < size; i++){
		arr[i] = 0;
	}
}
void solution(){

	vector<int> numbers(100);
	int range[100] = {};
	
	double error_previous = 0;
	int z = 13;
	int best_i, best_j, best_k;
	
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100;j++)
			for(int k = 1; k <= 100; k++){
				error_previous = 3400000;
				z = 0;
				for(int l = 0; l < 10000; l++){
					z = (i*z + j) % k;
					range[z-1]++;
				}

				double current_error = error(range, 10000, 100);
				if(error_previous  > current_error){
					error_previous = current_error;
					best_i = i;
					best_j = j;
					best_k = k;
				}
				initialize(range, 100);
			}
		

	}

	cout << "Best value is : " << error_previous << endl;
	cout << "A = " << best_i <<": B = " << best_j << ": C = " << best_k << endl;
	
}
int main(){
	solution();
    return 0;
}