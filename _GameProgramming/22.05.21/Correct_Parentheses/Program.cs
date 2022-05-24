using System;
using System.Text;

namespace Correct_Parentheses
{
    class Program
    {
        static void Main(string[] args)
        {
            Program prog = new Program();

            String input01 = "()()";
            System.Console.WriteLine("========== 01 ==========");
            System.Console.WriteLine(prog.solution(input01));

            String input02 = "(())()";
            System.Console.WriteLine("\n========== 02 ==========");
            System.Console.WriteLine(prog.solution(input02));

            String input03 = ")()(";
            System.Console.WriteLine("\n========== 03 ==========");
            System.Console.WriteLine(prog.solution(input03));

            String input04 = "(()(";
            System.Console.WriteLine("\n========== 04 ==========");
            System.Console.WriteLine(prog.solution(input04));
        }

        public bool solution(String input)
        {
            int chk = 0;
            int len = input.Length;

            for (int i = 0; i < len; i++)
            {
                if (chk < 0)
                    return false;

                if (input[i] == '(')
                    chk++;
                else if (input[i] == ')')
                    chk--;
            }
            if (chk != 0)
                return false;
            else
                return true;
        }
    }
}