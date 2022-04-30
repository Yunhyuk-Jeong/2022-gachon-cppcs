using System;

class 배열_삼차원배열
{
    static void Main()
    {
        
        int[,,] arr = new int[2, 2, 2]
        { { {1,2}, {3,4} }, { {5,6}, {7,8} } };
        
        Console.WriteLine("차수 출력: {0}", arr.Rank);
        
        Console.WriteLine("길이 출력: {0}", arr.Length);
        
        for (int i = 0; i < arr.GetLength(0); i++)
        {
            for (int j = 0; j < arr.GetLength(1); j++)
            {
                for (int k = 0; k < arr.GetLength(2); k++)
                {
                    Console.Write("{0}\t", arr[i, j, k]);
                }
                Console.WriteLine(); 
            }
            Console.WriteLine(); 
        }
    }
}
