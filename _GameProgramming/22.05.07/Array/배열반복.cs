using System;

public class 배열반복
{
    public static void Main()
    {
        string s = "안녕하세요.";
        Console.WriteLine(s);

        for (int i = 0; i < s.Length; i++)
        {
            Console.Write("{0}\t", s[i]);
        }
        Console.WriteLine();


        foreach (char c in s)
        {
            Console.Write("{0}\t", c);
        }
        Console.Write('\n');
    }
}
