using System;

class BreakDemo
{
    static void Main()
    {
        for (int i = 0; i < 100; i++)
        {
            if (i == 5)
            {
                break;
            }
            Console.Write($"{(i + 1)}번 반복\t");
        }
        Console.WriteLine();
    }
}

