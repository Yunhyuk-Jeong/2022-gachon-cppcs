using System;

class WhileEven
{
    static void Main()
    {
        int sum = 0;

        int i = 1;
        while (i <= 100)
        {
            if (i % 2 == 0)
            {
                sum += i;
            }
            i++;
        }

        Console.WriteLine($"1부터 100까지 짝수의 합: {sum}");
    }
}
