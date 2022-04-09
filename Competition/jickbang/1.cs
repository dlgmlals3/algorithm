using System;
using System.Collections.Generic;

public class UniqueNumbers
{
    public static IEnumerable<int>  FindUniqueNumbers(IEnumerable<int> numbers)
    {
        List<int> l = new List<int>();
        var dic = new Dictionary<int, int>();

        foreach (int number in numbers) {
            if (!dic.ContainsKey(number)) {
                dic.Add(number, 0);
            } else {
                dic[number] = dic[number] + 1;
            }
        }

        foreach (var number in dic) {
            if (number.Value == 0) {
                l.Add(number.Key);
            }
        }
        l.Sort();
        numbers = l;
        
        return numbers;
    }

    public static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        int[] numbers = new int[inputs.Length];

        for (int i = 0; i < inputs.Length; i++)
            numbers[i] = int.Parse(inputs[i]);
        
        foreach (var number in FindUniqueNumbers(numbers))
            Console.WriteLine(number);
    }
}