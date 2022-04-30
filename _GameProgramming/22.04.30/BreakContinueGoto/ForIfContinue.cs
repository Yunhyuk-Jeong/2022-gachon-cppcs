using System;

class ForIfContinue
{
    static void Main()
    {
        for (int i = 1; i <= 5; i++)
        {
            if (i % 2 == 0)
            {

                continue;
            }
            Console.WriteLine(i);
        }
    }
}
