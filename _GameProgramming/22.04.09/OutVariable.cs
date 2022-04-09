using System;

class OutVariable
{
    static void Main()
    {
        int r;
        if (int.TryParse("안녕", out r));
        {
            Console.WriteLine("{0}, r");
        }

        if(int.TryParse("1234", out var result))
        {
            Console.WriteLine(result);
        }
        Console.WriteLine(result);
    }
}