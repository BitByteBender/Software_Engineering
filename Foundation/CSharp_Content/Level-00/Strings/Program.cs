using System;

namespace Strings
{
    internal class Program
    {
	static void Main()
	{
	    string Fullname = "Soufiane Sdg";

	    Console.WriteLine($"Start truncationg from 3rd pos to the 7th char - 1 (3 + 4 - 1): {Fullname.Substring(3, 4)} ");
	    Console.WriteLine($"LowerCase: {Fullname.ToLower()}");
	    Console.WriteLine($"UpperCase: {Fullname.ToUpper()}");
	    Console.WriteLine($"Inserting: {Fullname.Insert(3, "VvV")}");
	    Console.WriteLine($"Replacing: {Fullname.Replace('u', 'o')}");
	    Console.WriteLine($"Index Of: {Fullname.IndexOf('e')}");
	    Console.WriteLine($"Contains: {Fullname.Contains('S')}");
	    Console.WriteLine($"Last Index Of Same Char: {Fullname.LastIndexOf('S')}");

	    string Pragraph = "RR, Lambo, Rarri, Brabus, Aston";
	    string[] Words0, Words1;

	    Words0 = Pragraph.Split(',');
	    Words1 = Pragraph.Split(", ");
	    
	    Console.WriteLine($"Spliting: {Words0[0]}##{Words0[Words0.Length - 1]}");
	    Console.WriteLine($"Spliting: {Words1[0]}##{Words1[Words1.Length - 1]}");

	    Pragraph = "***C++ > C#***";
	    Console.WriteLine($"Trimming: {Pragraph.Trim('*')}");
	    Console.WriteLine($"Trimming At The Start: {Pragraph.TrimStart('*')}");
	    Console.WriteLine($"Trimming At The End: {Pragraph.TrimEnd('*')}");

	    //String interpolation
	    string Firstname = "Soufiane", Lastname = "sdg";
	    Fullname = $"Sir. {Firstname} {Lastname}\n";

	    Console.Write(Fullname);
	    
	    Console.ReadKey();
	}
    }
}
