
using System;

class ArraySameIndex
{
    static void Main()
    {
        int[,] arr = new int[3, 3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    arr[i, j] = 1; 
                }
                else
                {
                    arr[i, j] = 0;
                }

                Console.Write(arr[i, j]);
            }
            Console.WriteLine();
        }
    }
}
