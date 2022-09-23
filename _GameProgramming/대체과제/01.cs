public void solution(string s)
{
    Dictionary<char, int> dictionary = new Dictionary<char, int>();
    foreach (var item in s)
    {
        if (dictionary.ContainsKey(item))
        {
            dictionary[item]++;
        }
        else
        {
            dictionary[item] = 1;
        }
    }

    if (dictionary.Where(x => x.Value != 1).Count() == dictionary.Count())
    {
        System.Console.WriteLine("중복없음");
        return;
    }

    foreach (var item in s)
    {
        if (dictionary[item] == 1)
        {
            System.Console.WriteLine(item);
            return;
        }
    }
}