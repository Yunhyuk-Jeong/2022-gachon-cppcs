using System;

class ForDemo
{
    static void Main()
    {
        for (int i = 1; i <= 5; i++)
        {
            Console.Write("{0}\t", i);
            if (i % 3 == 0)
            {
                Console.WriteLine();
            }
        }
        Console.WriteLine();

        int sum1 = 0;
        for (int i = 1; i <= 100; i++)
        {
            sum1 += i;
        }
        Console.WriteLine($"1부터 100까지의 합 : {sum1}");

        int sum2 = 0;
        for (int i = 1; i <= 100; ++i)
        {
            if (i % 2 == 0)
            {
                sum2 += i;
            }
        }
        Console.WriteLine($"1부터 100까지의 짝수의 합 : {sum2}");
    }
}
