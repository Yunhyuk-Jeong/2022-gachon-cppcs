using System;

class DigitSeparatorDescription
{
    static void Main()
    {
        
        int num = 1_000_000; 
        int[] numbers = { 0b1, 0B10, 0b0100, 0B0000_1000 };

        Console.WriteLine(num);
        foreach (var n in numbers)
        {
            Console.WriteLine(n);
        }
    }
}
