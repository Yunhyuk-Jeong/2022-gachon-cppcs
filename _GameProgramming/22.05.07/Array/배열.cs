using System;

namespace 배열
{
    class 배열
    {
        static void Main(string[] args)
        {
            int[] arr = new int[2];

            arr[0] = 100;
            arr[1] = 200;

            Console.WriteLine(arr[0]);
            Console.WriteLine(arr[1]);

            string[] msgs = new string[2];
            msgs[0] = "안녕하세요.";
            msgs[1] = "반갑습니다.";

            for (int i = 0; i < msgs.Length; i++)
                Console.WriteLine(msgs[i]);
        }
    }
}
