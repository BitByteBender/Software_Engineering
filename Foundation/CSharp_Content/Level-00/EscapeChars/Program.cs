using System;

namespace EscapeChars
{
    internal class Program
    {
	static void Main()
	{
	    Console.WriteLine("Escape Characters:");

	    //NewLine
	    Console.WriteLine("Newline:");
	    Console.WriteLine("WriteLine has a builtin (\\n)");
	    Console.Write("\\n is the way to add a newline\n\n");

	    //Tab
	    Console.Write("Tab:");
	    Console.WriteLine("\n\\t is used for adding \tTabs\n");

	    //Backspace
	    Console.WriteLine("Backspace:");
	    Console.Write("\\b is used for backspace like this (He \bllo)\n\n");

	    //Single quote
	    Console.Write("Single quote:\n");
	    Console.Write("\\\' is used to add \' \n");

	    //Double quotes
	    Console.Write("\nDouble quotes:\n");
	    Console.Write("\\\" is used to add \" \n");

	    //Backslash
	    Console.WriteLine("\nBackslash:");
	    Console.WriteLine("Yes\\No");

	    //System pause
	    Console.ReadKey();
	}
    }
}
