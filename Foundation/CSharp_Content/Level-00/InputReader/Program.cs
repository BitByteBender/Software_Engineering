using System;

namespace InputReader
{
    internal class Program
    {
	static void Main()
	{
	    Int16 Value = default(Int16);

	    Console.Write("Enter a value: ");
	    Value = Convert.ToInt16(Console.ReadLine());
	    Console.WriteLine("The Value entered is: {0}", Value);
	    
	    Console.ReadKey();
	}
    }
}
