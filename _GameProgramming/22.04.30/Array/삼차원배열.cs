﻿ System;

class 삼차원배열
{
    static void Main()
    {
        int[,,] intArray = new int[2, 3, 4] 
        { 
            
            { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } }, 
            
            { { 13, 14, 15, 16 }, { 17, 18, 19, 20 }, { 21, 22, 23, 24 } }
        };

        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                for (int k = 0; k < 4; k++) 
                {
                    Console.Write("{0,2} ", intArray[i, j, k]);
                }
                Console.Write("\n");
            }
            Console.WriteLine();
        }
    }
}
