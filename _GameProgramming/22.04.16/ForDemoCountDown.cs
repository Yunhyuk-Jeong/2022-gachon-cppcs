using System;

class ForDemoCountDown
{
    static void Main()
    {
        for (int i = 0; i < 5; i++)
        {
            Console.Write($"{i + 1}\t");
        }
        Console.WriteLine();

        for (int i = 5; i > 0; i--)
        {
            Console.Write($"{i}\t");
        }
        Console.WriteLine();
    }
}
