#include <iostream>
#include <functional>

enum Type //declaring a new enumeration Type (to specify sorting)
{
	decreasing, 
	increasing  
};

template <typename T, Type e> //he declaration of a function template parameter contains two variables - the type of data to be sorted and the order in which we will sort the data

void insertionSort(T arr[], int n)
{

	std::function<bool(T, T)> pre;

	switch (e) //conditional branch operator switch
	{
	case increasing: //sorting from smaller to larger
		pre = [](T x, T y) {return x > y ? true : false; };
		break;

	case decreasing: //sorting from larger to smaller
		pre = [](T x, T y) {return x < y ? true : false; };
		break;
	}

	for (int j = 1; j < n; j++) //we start with an element with index 1 (we finish last)
	{                           
		T key = arr[j]; //storing the current item in a temporary cell
		int i = j - 1; //variable i, which will count the previous elements 
		while (i >= 0 && pre(arr[i], key)) //check i, check whether two elements satisfy the sorting rule
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[++i] = key;

	}

	for (int i = 0; i < n; i++) //output
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl; //the gap between sorts

}

int main()
{
	{
		int arr[] = { 125, 24, 36, 2, 18 }; //creating an array, initializing it with elements
		insertionSort<int, increasing>(arr, 5); //initialize the template first, that is, we indicate that our array contains variables of type int, 
		//then we specify the sorting rule (in ascending order), then we pass the array itself and the number of elements.
	}

	{
		int arr[] = { 125, 24, 36, 2, 18 }; //creating an array, initializing it with elements
		insertionSort<int, decreasing>(arr, 5); //initialize the template first, that is, we indicate that our array contains variables of type int, 
		//then we specify the sorting rule (in descending order), then we pass the array itself and the number of elements.
	}
}