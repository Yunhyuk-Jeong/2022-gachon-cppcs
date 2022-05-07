using System;

class 국어점수_총점_평균_차이
{
    static void Main()
    {
        int[] kor = { 100, 90, 80, 70, 60 };
        int tot = 0;
        float avg = 0.0f;

        for (int i = 0; i < kor.Length; i++)
        {
            tot = tot + kor[i];
        }
        avg = tot / (float)kor.Length;

        Console.WriteLine("총점: {0,3}, 평균: {1,3}\n", tot, avg);
        for (int i = 0; i < kor.Length; i++)
        {
            float diff = kor[i] - avg;
            Console.WriteLine("점수: {0,3}, 차이: {1,3}", kor[i], diff);
        }
    }
}
