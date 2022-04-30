
using System;

class ArrayTwoDescription
{
    static void Main()
    {
        
        char[,] arr = new char[2, 2];

        
        arr[0, 0] = 'A';
        arr[0, 1] = 'B';

        arr[1, 0] = 'C';
        arr[1, 1] = 'D';

        
        Console.WriteLine($"{arr[0, 0]}, {arr[0, 1]}");
        Console.WriteLine($"{arr[1, 0]}, {arr[1, 1]}");
    }
}
