using System;

namespace 배열_이차원배열
{
    class 배열_이차원배열
    {
        static void Main(string[] args)
        {
            int[,] arr = { { 10, 20 }, { 30, 40 } };
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Console.Write("{0}\t", arr[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            int[,] scores = new int[2, 2];
            scores[0, 0] = 10;
            scores[0, 1] = 20;
            scores[1, 0] = 30;
            scores[1, 1] = 40;
            for (int i = 0; i < scores.GetLength(0); i++)
            {
                for (int j = 0; j < scores.GetLength(1); j++)
                {
                    Console.Write("{0}\t", scores[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            int[] arr1 = { 100, 90, 80 };
            Console.WriteLine("배열의 차수: {0}", arr1.Rank);
            for (int i = 0; i < arr1.Length; i++)
            {
                Console.WriteLine("{0}", arr1[i]);
            }
            Console.WriteLine();

            int[,] arr2 = new int[,] { { 10, 20, 30 }, { 40, 50, 60 } };

            Console.WriteLine("배열의 차수: {0}", arr2.Rank);
            for (int i = 0; i < arr2.GetLength(0); i++)
            {
                for (int j = 0; j < arr2.GetLength(1); j++)
                {
                    Console.Write("{0}\t", arr2[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
