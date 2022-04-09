using System;

class PositiveNegativeZero
{
    static void Main()
    {
        int number = -10;

        if(number > 0)
        {
            Console.WriteLine($"{number}은 양수입니다.");
        }
        else if (number < 0)
        {
            Console.WriteLine($"{number}은 음수입니다.");
        }
        else
        {
            Console.WriteLine($"{number}은 0입니다.");
        }
    }
}