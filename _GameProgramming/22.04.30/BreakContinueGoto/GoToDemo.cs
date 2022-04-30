using System;

class GoToDemo
{
    static void Main()
    {
        Console.WriteLine("시작");
    Start:
        Console.WriteLine("0, 1, 2 중 하나 입력: _\b");
        int chapter = Convert.ToInt32(Console.ReadLine());

        if (chapter == 1)
        {
            goto Chapter1;
        }
        else if (chapter == 2)
        {
            goto Chapter2;
        }
        else
        {
            goto End;
        }

    Chapter1:
        Console.WriteLine("1장입니다.");

    Chapter2:
        Console.WriteLine("2장입니다.");

        goto Start;

    End:
        Console.WriteLine("종료");
    }
}
