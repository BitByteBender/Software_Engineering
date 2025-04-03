using System;

namespace FormattedStr
{
    internal class Program
    {
	static void Main()
	{
	    Console.WriteLine("{0} {1} {2}", "My name", "is", "Soufiane");
	    Console.Write("This {0} about {1} {2}{3}", "is", "formatted", "string", '!');
	    Console.Write('\n');

	    Console.ReadKey();
	}
    }
}
