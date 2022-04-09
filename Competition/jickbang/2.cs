using System;
using System.Collections.Generic;
using System.Linq;

public class Prefix
{
    public static async IEnumerable<string> AllPrefixes(int prefixLength, IEnumerable<string> words)
    {
        var dic = new Dictionary<string, int>();
        SortedSet<String> sortedSet = new SortedSet<string>();
        foreach(string word in words) {
            if (word.Length < prefixLength) {
                continue;
            }
            string prefix = word.Substring(0, prefixLength);
            sortedSet.Add(prefix);
        }
        List<string> l;
        foreach(string w in sortedSet) {
            l.Add(w);
        }
        words = l; 
		return words;	
    }
    
    public static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        foreach (var p in AllPrefixes(3, inputs))
            Console.WriteLine(p);
    }
}