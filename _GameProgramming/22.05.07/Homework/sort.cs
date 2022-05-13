using System;

namespace Homework
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();

            System.Console.WriteLine("========== 01 ==========");
            int[] arr01 = { 5, 9, 7, 10 };
            int divisor01 = 5;
            int[] answer01 = sol.solution(arr01, divisor01);
            for (int i = 0; i < answer01.Length; i++)
                System.Console.WriteLine(answer01[i]);

            System.Console.WriteLine("\n========== 02 ==========");
            int[] arr02 = { 2, 36, 1, 3 };
            int divisor02 = 1;
            int[] answer02 = sol.solution(arr02, divisor02);
            for (int i = 0; i < answer02.Length; i++)
                System.Console.WriteLine(answer02[i]);

            System.Console.WriteLine("\n========== 03 ==========");
            int[] arr03 = { 3, 2, 6 };
            int divisor03 = 10;
            int[] answer03 = sol.solution(arr03, divisor03);
            for (int i = 0; i < answer03.Length; i++)
                System.Console.WriteLine(answer03[i]);
        }
    }

    public class Solution
    {
        public int[] solution(int[] arr, int divisor)
        {
            int[] answer = new int[arr.Length];

            int cnt = 0;

            System.Array.Sort(arr);

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] >= divisor && arr[i] % divisor == 0)
                {
                    answer[cnt] = arr[i];
                    cnt++;
                }
            }

            if (cnt == 0)
            {
                answer[0] = -1;
                cnt++;
            }

            int[] sorted = new int[cnt];

            for (int i = 0; i < cnt; i++)
                sorted[i] = answer[i];

            return sorted;
        }
    }

}
