using System;

class WhileSum
{
    static void Main()
    {
        const int N = 100;
        int sum = 0;

        int i = 1;
        while (i <= N)
        {
            sum += i;
            i++;
        }

        Console.WriteLine($"1부터 {N}까지의 합: {sum}");
    }
}
