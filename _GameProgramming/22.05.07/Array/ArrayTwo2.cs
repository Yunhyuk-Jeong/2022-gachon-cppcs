using System;

class ArrayTwo2
{
    static void Main()
    {
        
        int[,] intArray = new int[2, 3] { { 1, 2, 3 }, { 4, 5, 6 } };

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Console.Write($"{intArray[i, j]}_");
            }
            Console.Write("\n"); 
        }
    }
}
