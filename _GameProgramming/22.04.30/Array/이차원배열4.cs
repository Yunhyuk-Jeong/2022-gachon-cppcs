﻿using System;

class 이차원배열4
{
    static void Main()
    {
        
        int[,] intArray = { { 1, 2, 3 }, { 4, 5, 6 } };

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
