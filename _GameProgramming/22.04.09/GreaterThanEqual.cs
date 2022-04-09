using System;

class GreaterThanEqual
{
    static void Main()
    {
        Console.WriteLine("첫 번째 수 : ");
        int first = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("두 번째 수 : ");
        int second = Convert.ToInt32(Console.ReadLine());

        if (first >= second)
        {
            Console.WriteLine("큰 값 : {0}", first);
        }
        else if (first <= second)
        {
            Console.WriteLine("큰 값 : {0}", second);
        }
    }
}