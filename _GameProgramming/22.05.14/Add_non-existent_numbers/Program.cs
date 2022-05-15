using System;
using System.Linq;

namespace Add_non_existent_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            Program prog = new Program();

            System.Console.WriteLine("========== 01 ==========");
            int[] numbers01 = { 1, 2, 3, 4, 6, 7, 8, 0 };
            System.Console.WriteLine(prog.solution(numbers01));

            System.Console.WriteLine("\n========== 02 ==========");
            int[] numbers02 = { 5, 8, 4, 0, 6, 7, 9 };
            System.Console.WriteLine(prog.solution(numbers02));
        }

        public int solution(int[] numbers)
        {
            int answer = 0;
            for (int i = 0; i < 10; i++)
            {
                answer += i;
            }
            answer -= numbers.Sum();
            return answer;
        }
    }
}
