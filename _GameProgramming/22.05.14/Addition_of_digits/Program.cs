using System;

namespace Addition_of_digits
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();

            int n = int.Parse(Console.ReadLine());

            System.Console.WriteLine("\n========== Only Intiger ==========");
            Console.WriteLine(sol.solution01(n));

            System.Console.WriteLine("\n=========== Use String ===========");
            Console.WriteLine(sol.solution02(n));
        }
    }

    public class Solution
    {
        public int solution01(int n)
        {
            int answer = 0;

            while (n > 0)
            {
                answer += n % 10;
                n = n / 10;
            }
            return answer;
        }

        public int solution02(int n)
        {
            int answer = 0;

            string nString = n.ToString();

            for (int i = 0; i < nString.Length; i++)
            {
                answer += (int)Char.GetNumericValue(nString[i]);
            }
            return answer;
        }
    }
}
