
using System;

class 일차원배열1
{
    static void Main()
    {
        int[] intArray; 
        intArray = new int[3]; 

        intArray[0] = 1; 
        intArray[1] = 2;
        intArray[2] = 3;

        
        for (int i = 0; i < 3; i++) 
        {
            Console.WriteLine($"{i}번째 인덱스: {intArray[i]}");
        }

        
        foreach (int intValue in intArray)
        {
            Console.WriteLine("{0}", intValue);
        }
    }
}
