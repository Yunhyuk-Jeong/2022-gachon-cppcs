using System;

class ConditionalOperator
{
    static void Main()
    {
        int number = 3;

        string result = (number % 2 == 0) ? "짝수" : "홀수";

        Console.WriteLine($"{number}은(는) {result}입니다.");
    }
}