using System;

class WhileBreak
{
    static void Main()
    {
        int goal = 22;
        int sum = 0;

        int i = 1;
        while (i <= 10)
        {
            sum += i;

            if (sum >= goal)
            {
                break;
            }

            i++;
        }

        Console.WriteLine(
            $"1부터 {i}까지의 합은 {sum}이고, 목표치 {goal}이상을 달성했습니다.");
    }
}
