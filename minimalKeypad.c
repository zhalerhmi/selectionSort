
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i = 0, j, max_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the max element in unsorted array
        max_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }

        // Swap the found minimum element with the first element
        swap(&arr[max_idx], &arr[i]);
    }
}
/*function to calculate the total number of letters that all keys can include*/
int ArrElemSum(int keyArray[], int keyNum)
{
    int i, sum = 0;

    for (i = 0; i < keyNum; i++)
    {
        sum += keyArray[i];
    }
    return sum;
}

// Driver program to test above functions
int main(void)
{
    //input the number of letters
    int lettersNum;
    scanf("%d", &lettersNum);

    //input the frequency of letters in a list
    int *lettersFreqArray;
    lettersFreqArray = (int *)malloc(sizeof(int) * lettersNum);

    for (int i = 0; i < lettersNum; i++)
    {
        scanf("%d", &lettersFreqArray[i]);
    }

    //input the number of keys
    int keysNum;
    scanf("%d", &keysNum);

    //input the numbers letters that each can contain
    int *keyArray;
    keyArray = (int *)malloc(sizeof(int) * keysNum);

    for (int i = 0; i < keysNum; i++)
    {
        scanf("%d", &keyArray[i]);
    }

    //variables
    int counter = 0, key, l=0;

    //sort the freqArray
    selectionSort(lettersFreqArray, lettersNum);

    int keyCapacity = ArrElemSum(keyArray, keysNum);

    if (keyCapacity < lettersNum)
    {
        counter = -1;
    }
    //else proceed with the solution
    else
    {

        /*find the min strokes number*/
        //j = strokes -1 > position if of the letter in each key
        for (int j = 0; j < keyCapacity; j++)
        {

            key = 0;
           

            while (l < lettersNum && key < keysNum)
            {
                if (j < keyArray[key])
                {

                    printf(" strokes:%d , key number %d, key capacity %d , letterNum %d \n", j, key, keyArray[key], l);
                    counter += lettersFreqArray[l] * (j + 1);
                    l++;
                }
                key++;
            }
        }
    }
    //find the min strokes number

    printf("%d \n", counter);

    return 0;
}