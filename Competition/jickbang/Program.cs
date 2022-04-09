using System;
using System.Collections.Generic;
using System.Linq;

public class Prefix2
{
    public static IEnumerable<string> AllPrefixes(int prefixLength, IEnumerable<string> words)
    {
        throw new InvalidOperationException("Waiting to be implemented.");
    }
    
    public static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        foreach (var p in AllPrefixes(3, inputs))
            Console.WriteLine(p);
    }
}