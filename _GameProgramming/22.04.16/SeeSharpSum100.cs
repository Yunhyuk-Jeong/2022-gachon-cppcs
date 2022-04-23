using System;

class SeeSharpSum100
{
    static void Main()
    {
        int sum = 0;

        for (int i = 1; i <= 100; i++)
        {
            sum += i;
        }

        Console.WriteLine("1부터 100까지 정수의 합: {0}",  sum);
    }
}
