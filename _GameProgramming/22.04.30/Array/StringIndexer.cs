
using System;

class StringIndexer
{
    static void Main()
    {
        Console.WriteLine("ABC"[0]); 
        Console.WriteLine("ABC"[1]); 
        Console.WriteLine("ABC"[2]); 

        Console.WriteLine("ABC".GetType()); 
        Console.WriteLine("ABC"[0].GetType()); 
    }
}
