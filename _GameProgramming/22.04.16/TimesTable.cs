using System;

class TimesTable
{
    static void Main()
    {
        for (int i = 2; i <= 9; i++)
        {
            Console.Write($"{i, 4}단  ");
        }
        Console.WriteLine();

        for (int i = 1; i <= 9; i++)
        {
            for (int j = 2; j <= 9; j++)
            {
                Console.Write($"{j}*{i}={j * i, 2}  ");
            }
            Console.WriteLine();
        }
    }
}
