using System;

class ArrayWithVarKeyword
{
    static void Main()
    {
        
        var i = 5; 
        Console.WriteLine("i : {0}, 타입 : {1}", i, i.GetType());

        
        var s = "Hello";
        Console.WriteLine("s : {0}, 타입 : {1}", s, s.GetType());

        
        var numbers = new int[] { 1, 2, 3 };
        foreach (var item in numbers) 
        {
            Console.WriteLine("item : {0}, 타입 : {1}", item, item.GetType());
        }
    }
}
