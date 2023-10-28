public class Zad1
{
    public static void main(String[] args)
    {
        int[] arr1 = new int[]{1, 4, 7, 2, 2, 5, 9, 3, 2, 7};
        printArray(arr1);
        int[] out1 = sortAndFilter(arr1, 2);
        printArray(out1);
        System.out.println("------------------");
        int[] arr2 = new int[]{7, 5, 9, 8, 7, 6, 3, 4, 7, 5};
        printArray(arr2);
        int[] out2 = sortAndFilter(arr2, 7);
        printArray(out2);
        System.out.println("------------------");
        int[] arr3 = new int[]{7, 5, 9, 8, 7};
        printArray(arr3);
        int[] out3 = sortAndFilter(arr3, 9);
        printArray(out3);

    }

    public static int[] sortAndFilter(int[] arr, int key)
    {
        int count = 0;
        for(int val: arr)
        {
            if(val != key)
            {
                count++;
            }
        }

        int[] copy = new int[count];
        int indexCopy = 0;
        for(int el: arr)
        {
            if(el != key)
            {
                copy[indexCopy] = el;
                indexCopy++;
            }
        }

        sortArr(copy);
        return copy;
    }

    public static void sortArr(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
 
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }


    public static void printArray(int[] arr)
    {
        System.out.print("[ ");
        for(int el: arr)
        {
            System.out.print(el + " ");
        }
        System.out.println("]");
    }
}