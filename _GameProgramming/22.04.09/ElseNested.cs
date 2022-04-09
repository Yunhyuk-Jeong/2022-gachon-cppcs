using System;

class ElseNested
{
    static void Main()
    {
        Console.WriteLine("문자를 입력하세요 (y/n/c) : ");
        char input = Convert.ToChar(Console.ReadLine());

        if(input == 'y')
        {
            Console.WriteLine("Yes");
        }
        else if(input == 'n')
        {
            Console.WriteLine("No");
        }
        else if(input == 'c')
        {
            Console.WriteLine("Cancel");
        }
    }
}