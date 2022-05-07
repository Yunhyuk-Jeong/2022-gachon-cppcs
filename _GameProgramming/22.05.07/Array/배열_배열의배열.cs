using System;

namespace 배열_배열의배열
{
    class 배열_배열의배열
    {
        static void Main(string[] args)
        {
            Console.WriteLine("2016년 2월은 며칠까지? {0}", DateTime.DaysInMonth(2016, 2));


            int[][] intDaysInMonth = new int[12][];


            for (int i = 0; i < 12; i++)
            {
                intDaysInMonth[i] = new int[DateTime.DaysInMonth(DateTime.Now.Year, i + 1)];
                for (int j = 0; j < DateTime.DaysInMonth(DateTime.Now.Year, i + 1); j++)
                {
                    intDaysInMonth[i][j] = 1;
                }
            }


            int sum = 0;
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < DateTime.DaysInMonth(DateTime.Now.Year, i + 1); j++)
                {
                    sum += intDaysInMonth[i][j];
                }
            }
            Console.WriteLine("2016년 1년 전체 일수: {0}", sum);
        }
    }
}
