public void solution(int[] A)
{
    int[] min = new int[A.Length];
    int[] minPos = new int[A.Length];

    for (int i = 0; i < A.Length; i++)
    {
        if (i == 0)
        {
            min[i] = A[0];
            minPos[i] = i;
            continue;
        }

        if (A[i] <= min[i - 1])
        {
            min[i] = A[i];
            minPos[i] = i;
        }
        else
        {
            min[i] = min[i - 1];
            minPos[i] = minPos[i - 1];
        }
    }

    int max = int.MinValue;
    int pos = -1;
    for (int i = 0; i < A.Length; i++)
    {
        if (A[i] - min[i] > max)
        {
            max = A[i] - min[i];
            pos = i;
        }
    }

    Console.WriteLine("Max Range : {0}-{1}", minPos[pos], pos);
    Console.WriteLine("Max Value : {0}", max);
}
    }