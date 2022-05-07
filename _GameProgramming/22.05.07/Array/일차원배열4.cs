using System;

class 일차원배열4
{
    static void Main()
    {
        
        
        int[] intArray = { 1, 2, 3 };

        
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
