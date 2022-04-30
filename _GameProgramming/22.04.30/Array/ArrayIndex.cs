using System;

class ArrayIndex
{
    static void Main()
    {
        
        int[] array = { 1, 2, 3 };
        int index = 0; 

        Console.WriteLine(array[index++]); 
        Console.WriteLine(array[index++]); 
        Console.WriteLine(array[index++]); 

        Console.WriteLine(array[--index]); 
        Console.WriteLine(array[--index]); 
        Console.WriteLine(array[--index]); 
    }
}
