using System;

class 배열의배열
{
    static void Main()
    {
        
        int[][] intDaysInMonth;
        intDaysInMonth = new int[12][]; 

        for (int i = 0; i < 12; i++)
        {
            intDaysInMonth[i] = new int[
                DateTime.DaysInMonth(DateTime.Now.Year, i + 1)];

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
        Console.WriteLine(sum);
    }
}
