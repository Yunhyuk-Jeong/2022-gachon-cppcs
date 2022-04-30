using System;

class BreakInfiniteLoop
{
    static void Main()
    {
        int number = 0;

        while (true)
        {
            Console.WriteLine(++number);

            if (number >= 5)
            {
                break;
            }
        }
    }
}
