using System;

class ContinueExam
{
    static void Main()
    {
        int sum = 0;
        for (int i = 1; i <= 100; i++)
        {

            if (i % 7 == 0)
            {
                continue;
            }
            sum += i;
        }
        Console.WriteLine(sum);
    }
}
