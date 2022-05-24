using System;
using System.Text;

namespace Biggerst_Number
{
    class Program
    {
        static void Main(string[] args)
        {
            Program prog = new Program();

            int[] numbers01 = { 6, 10, 2 };
            System.Console.WriteLine("========== 01 ==========");
            System.Console.WriteLine(prog.solution(numbers01));

            int[] numbers02 = { 3, 30, 34, 5, 9 };
            System.Console.WriteLine("\n========== 02 ==========");
            System.Console.WriteLine(prog.solution(numbers02));
        }

        public string solution(int[] numbers)
        {
            string answer = "";
            StringBuilder sb = new StringBuilder();
            string[] tempString = new string[numbers.Length];
            int[] testInt = new int[numbers.Length];

            Array.Sort(numbers, (x, y) => string.Compare(y.ToString() + x.ToString(), x.ToString() + y.ToString()));

            for (int i = 0; i < numbers.Length; i++)
                sb.Append(numbers[i].ToString());

            answer = sb.ToString();

            int count = 0;

            foreach (var item in answer)
                if (item == '0')
                    count++;

            if (count == numbers.Length)
                return "0";

            else
                return answer;
        }
    }
}