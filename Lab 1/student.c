/* Author: Bea Ricafort 
   Pennstate ID: 929836057
   Date: 2/14/25
    */
    
    
    
/***
 *      ______ .___  ___. .______     _______.  ______              ____    __   __  
 *     /      ||   \/   | |   _  \   /       | /      |            |___ \  /_ | /_ | 
 *    |  ,----'|  \  /  | |  |_)  | |   (----`|  ,----'              __) |  | |  | | 
 *    |  |     |  |\/|  | |   ___/   \   \    |  |                  |__ <   | |  | | 
 *    |  `----.|  |  |  | |  |   .----)   |   |  `----.             ___) |  | |  | | 
 *     \______||__|  |__| | _|   |_______/     \______|            |____/   |_|  |_| 
 *                                                                                   
 */



#include "student.h"
#include <stdbool.h>

// Takes an array of integers and the length of the array as input, and returns the smallest positve integer in the array. Return 0 otherwise
int smallest_pos(int *array, int length) {  
	int min = 0; // Minimum Value

	for (int i = 0; i < length - 1; i++) {
		if (0 < array[i] && array[i] < array[i + 1]) { // If current number is positive & less than next number, new minimum
			min = array[i];
	}
	}
	
	if (0 < array[length - 1] && array[length - 1] < min) { // If last number in array is minimum
		min = array[length - 1];
	}
	return min;
	}
	
// Takes an array of integers, the length of the array and integer k as input, and returns the sum of the integers mod k in the array.
int sum_modulo(int *array, int length, int k)  {
	int sum = 0; // Sum Value
	for (int i = 0; i < length; i++) {
		int mod = (array[i] % k); // Modulo Current Number 
		if (mod < 0) {
			sum += (mod + k); // Negative Modulo
		} else {
			sum += (mod); // Positive Modulo
		}
	}
	return sum;
	}
	

//  Rotates the values of a, b, and c once in a clockwise direction.
void rotate(int *a, int *b, int *c){
	// Function Body
	// Saves original values of a & b
	int orig_a = *a; 
	int orig_b = *b;

	*a = *c;
	*b = orig_a;
	*c = orig_b;

	}

// Sorts an array in descending order 
void sort(int *array, int length){
	// Function Body
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] < array[j + 1]) { // If next number in array is greater, swap current number with next number
				int temp = array[j]; // Saves original number of current element 
				array[j] = array[j + 1];
				array[j + 1] = temp;
			} 
		}
	}
	}
	
//Takes an apartment number (int) and returns: 
//0 if the apartment belongs to Building 0 (0-99), 
//1 if it belongs to Building 1 (100-199), 
//2 if it belongs to building 2 (200-299) 
//-1 for invalid apartment numbers (outside 0-299).
int find_building(int apartmentNumber){
	// Function Body
	if (0 <= apartmentNumber && apartmentNumber <= 99) { // Building 0 (Apt. 0-99)
		return 0;
	} else if (100 <= apartmentNumber && apartmentNumber <= 199) { // Building 1 (Apt. 100-199)
		return 1;
	} else if (200 <= apartmentNumber && apartmentNumber <= 299) { // Building 2 (Apt. 200-299)
		return 2;
	} else { // Invalid Apt. Numbers
		return -1;
	}
	}

// Takes an array of integers and the length of the array as input and cubes every positive element of the array that is an Armstrong number. 
void cube_armstrongs(int *array, int length) {
	// Function Body
	for (int i = 0; i < length; i++) {
		if (array[i] > 0) {
			int armstrong = 0;
			int curr_num = array[i];
			int num_dig = calc_dig(curr_num); // Calculates number of digits in current number
			while(curr_num) { // Iterates through digits of current number
				int digit = curr_num % 10; // Finds last digit
				armstrong += expon(digit, num_dig); // Adds each digit raised to total number of digits to Armstrong value
				curr_num /= 10; // Removes last digit
			}
			if (array[i] == armstrong) { // If current number meets Armstrong conditions
				array[i] = expon(array[i], 3); // Cubes current number
			}
		}
	}
	}

int expon(int num, int power) {
	int orig_num = num; // Saves original number
	for (int i = 0; i < power - 1; i++) {
		num *= orig_num;
	}
	return num; 
	}

int calc_dig(int num) {
	int num_dig = 0;
	while(num) { // Iterates through digits
		num /= 10; // Removes last digit
		num_dig += 1; // Adds to digit count
	}
	return num_dig;
}
	
//Take an array of integers and length of the array as input and double every spy number of that array
void double_spy(int *array, int length){
	// Function Body
	for (int i = 0; i < length; i++) {
		int curr_num = array[i];
		if (curr_num > 0) { // Current number must be positive
			int spy_sum = 0;
			int spy_product = 1;
			while(curr_num) { // Iterates through digits
				spy_sum += (curr_num % 10); // Sum of Digits
				spy_product *= (curr_num % 10); // Product of Digits
				curr_num /= 10; // Removes last digit
			}
			if (spy_sum == spy_product) {
				array[i] = 2 * array[i]; // Doubles spy number if current number meets spy number conditions
			}
		}
	}
	}

//Take a number and return its second bit from the right in its binary form 
int second_bit(int num){
	// Function Body
	int binary_num[1000]; // Initializes array that stores binary number digits
	int i = 0;
	while (num > 0) {
		binary_num[i] = num % 2; // Binary Digit = Number Modulo 2
		num /= 2;
		i++;
	}
	return binary_num[i - 2]; // Returns second-to-last number in array
	}

/*CWD /home/cmpsc311/Desktop/Labs/Test Labs/Lab1 */

/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp25-lab1-BeaAngelaRicafort */
