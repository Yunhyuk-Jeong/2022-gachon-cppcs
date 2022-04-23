using System;

class ForIncrement
{
    static void Main()
    {
        for (int i = 0; i < 5; i = i + 2)
        {
            Console.WriteLine(i);
        }
    }
}