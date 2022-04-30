using System;

class DoWhileSum
{
    static void Main()
    {
        int sum = 0;

        int i = 1;
        do
        {
            sum += i;
            i++;
        } while (i <= 5);

        Console.WriteLine($"합계: {sum}");
    }
}
