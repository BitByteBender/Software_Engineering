using System;

namespace Main
{
    internal class Program
    {
	static void Main()
	{
	    // this works like std::cout<<"Anything here"<<endl;
	    Console.WriteLine("This is a test of .NET Framework on Linux!\n");
	    Console.WriteLine("Tried to use Wine but it didn\'t work :(");
	    Console.WriteLine("But i got it working using mono :)");
	    Console.WriteLine("Lets try to calculate this: " + (15 + 5));

	    // this works like system pause in C++
	    Console.ReadKey();
	}
    }
}
