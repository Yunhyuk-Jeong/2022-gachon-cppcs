using System;

public class 배열_일차원배열
{
    public static void Main()
    {
        
        int variable = 1234;
        Console.WriteLine($"변수 값 출력: {variable}");

        
        int[] array;

        
        array = new int[3];
        
        
        array[0] = 10;
        array[1] = 20;
        array[2] = 30;

        
        Console.WriteLine("배열 값 출력: ");
        for (int i = 0; i < array.Length; i++)
        {
            Console.WriteLine(array[i]);
        }        
        
        
        int[] arr = { 10, 20, 30 };
        Console.WriteLine("{0}, {1}, {2}", arr[0], arr[1], arr[2]);

        int[] a = new int[3];
        a[0] = 10; a[1] = 20; a[2] = 30;
        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine("{0}", a[i]);
        }

        string[] sites = new string[] {"데브렉", "닷넷코리아", "비주얼아카데미" };
        for (int i = 0; i < sites.Length; i++)
        {
            Console.Write("{0}\t", sites[i]);
        }
        Console.WriteLine();
    }
}
