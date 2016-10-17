#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int size;

void add(int idx, int value,int *arr)
{

while(idx<=size)
{
    *(arr+idx) = *(arr+idx)+value;

	idx +=  (idx & -idx);
}
	

}

int sum_prefix(int idx,int *arr)
{
	int result = 0;
   while(idx!=0)
   {
   	result += *(arr+idx);
   	idx -= idx & -idx;

   }

   return result;

}


int main()
{ 
	// vector <int> array {1,2,3,4,5,6,7,8,9,10};
	// vector<int> array = { 1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5 };   // you can apply this method in c++11 but not in previous c++ compiler so avoid this

    int array[] = { 1, 2, 3, 4, 5};

  /*  vector <int> v  (array , array+sizeof(array)/sizeof(array[0])+1);  //Convert array into vector

	for ( int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}

	add(v);
	*/

	 size = sizeof(array)/sizeof(int);
	cout<<size;

	int arr[size+1];

	for(int i = 0;i<size+1;i++)
	{
		arr[i]=0;
	}

	for(int i=1; i<size+1; i++)
	{
		add(i,array[i-1],arr);
	}

	for(int i=0;i<size+1;i++)
		cout<<arr[i]<<"\n";

	

	cout<<sum_prefix(1,arr)<<" "<<sum_prefix(2,arr)<<" "<<sum_prefix(4,arr)<<" "<<sum_prefix(5,arr);

	return 0;
}
