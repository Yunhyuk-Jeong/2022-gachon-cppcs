using System;

class 일차원배열3
{
    static void Main()
    {
        
        
        var intArray = new int[] { 1, 2, 3 };

        
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
