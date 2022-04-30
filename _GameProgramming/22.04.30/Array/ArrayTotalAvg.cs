using System;

class ArrayTotalAvg
{
    static void Main()
    {
        int[] kor = new int[3]; 
        int sum = 0; 
        float avg = 0; 

        kor[0] = 100; 
        kor[1] = 90;
        kor[2] = 80;

        sum = kor[0] + kor[1] + kor[2];     
        avg = sum / (float)3.0;             

        
        Console.WriteLine($"총점: {sum}, 평균: {avg:0.00}");
    }
}
