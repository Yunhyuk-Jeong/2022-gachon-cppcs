



using System;

class TwoDimensionalArray
{
    static void Main()
    {
        
        int[] oneArray;         
        int[,] twoArray;        
        int[,,] threeArray;     

        
        oneArray = new int[2] { 1, 2 };
        twoArray = new int[2, 2] { { 1, 2 }, { 3, 4 } };
        threeArray = new int[2, 2, 2] { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };

        
        
        for (int i = 0; i < 2; i++)
        {
            Console.Write($"{oneArray[i]}\t");
        }
        Console.WriteLine();

        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                Console.Write($"{twoArray[i, j]}\t");
            }
            Console.WriteLine();
        }
        Console.WriteLine();

        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    Console.Write($"{threeArray[i, j, k]}\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        Console.WriteLine();
    }
}
