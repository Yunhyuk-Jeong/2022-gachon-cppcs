using System;

class BinaryLiteralDemo
{
    static void Main()
    {
        
        
        int[] numbers = { 0b1, 0B10, 0b0100, 0B00001000 }; 

        foreach (var n in numbers)
        {
            Console.WriteLine(n);
        }
    }
}
