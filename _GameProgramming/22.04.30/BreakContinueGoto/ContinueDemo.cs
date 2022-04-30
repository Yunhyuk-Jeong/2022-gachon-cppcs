using System;

class ContinueDemo
{
    static void Main()
    {
        int sum = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (i % 3 == 0)
            {
                continue;
            }
            sum += i;
        }
        Console.WriteLine("SUM: {0}", sum);
    }
}
