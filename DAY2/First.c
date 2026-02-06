#include <stdio.h>

int main() {
    int n, pos;

  
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

  
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
	{
        	scanf("%d", &arr[i]);
    	}

    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

 
    if (pos < 1 || pos > n)
	{
        	printf("Invalid position!");
        	return 0;
    	}


    for (int i = pos - 1; i < n - 1; i++)
	{
        	arr[i] = arr[i + 1];
    	}

    
    printf("Array after deletion:\n");
    for (int i = 0; i < n - 1; i++)
	{
        	printf("%d ", arr[i]);
    	}

    return 0;
}