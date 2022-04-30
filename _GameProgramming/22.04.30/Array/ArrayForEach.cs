
using System;

class ArrayForEach
{
    static void Main()
    {
        
        float[] arr = { 10.5f, 20.1f, 30.2f };

        float sum = 0.0f; 

        foreach (float f in arr) 
        {
            sum += f; 
        }

        Console.WriteLine(sum); 
    }
}










