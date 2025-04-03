using System;

namespace Main
{
    internal class Program
    {
	static void Main()
	{
	    // this works like std::cout<<"Anything here";
	    Console.Write("This is a test of .NET Framework on Linux!\n");
	    Console.Write("Tried to use Wine but it didn\'t work :(");
	    Console.Write("But i got it working using mono :)");
	    Console.Write("Lets try to calculate this: " + (20 + 5));

	    // this works like system pause in C++
	    Console.ReadKey();
	}
    }
}
