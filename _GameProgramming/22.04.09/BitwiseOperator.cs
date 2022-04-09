using System;

class BitwiseOperator
{
    static void Main()
    {
        var x = Convert.ToInt32("1010", 2);
        var y = Convert.ToInt32("0110", 2);

        var and = x & y;
        Console.WriteLine($"{and} : {Convert.ToString(and, 2)}");

        var or = x | y;
        Console.WriteLine($"{or} : {Convert.ToString(or, 2)}");

        var not = -x;
        Console.WriteLine($"{not} : {Convert.ToString(not, 2)}");
    }
}