#include <iostream>
#include <functional>

enum Type //declaring a new enumeration Type (to specify sorting)
{
	decreasing, 
	increasing  
};

template <typename T, Type e> //the declaration of a function template parameter contains two variables - the type of data to be sorted and the order in which we will sort the data
void bubbleSort(T arr[], int n)
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

	for (int i = 0; i < n - 1; i++) // a loop in which we find all the elements of the array, except the last one
	{
		
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (pre(arr[j], arr[j + 1]))
			{
				T temp =  arr[j + 1];   //swapping variables
				arr[j + 1] = arr[j];
				arr[j] = temp;
				
			}
		}
		
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
		bubbleSort<int, increasing>(arr, 5); //initialize the template first, that is, we indicate that our array contains variables of type int,
		                                     //then we specify the sorting rule (in ascending order), then we pass the array itself and the number of elements.
	}
	
	{
		int arr[] = { 125, 24, 36, 2, 18 }; //creating an array, initializing it with elements
		bubbleSort<int, decreasing>(arr, 5); //initialize the template first, that is, we indicate that our array contains variables of type int, 
		                                     //then we specify the sorting rule (in descending order), then we pass the array itself and the number of elements.
	}
}