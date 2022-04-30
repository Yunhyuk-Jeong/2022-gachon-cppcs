using System;

class BreakPractice
{
    static void Main()
    {
        Console.Write("1부터 10까지 하나만 입력하세요: ");
        int number = Convert.ToInt32(Console.ReadLine());

        for (int i = 1; i <= 10; i++)
        {
            Console.WriteLine(i);
            if (i == number)
            {
                break;
            }
        }
    }
}
