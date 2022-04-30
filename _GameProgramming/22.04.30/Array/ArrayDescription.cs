
using System;

class ArrayDescription
{
    static void Main()
    {
        
        ushort[] numbers;

        
        numbers = new ushort[2]; 

        
        numbers[0] = 3840;
        numbers[1] = 2160;

        
        Console.WriteLine($"{numbers[0]} * {numbers[1]}"); 
    }
}
