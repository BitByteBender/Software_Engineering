using System;

namespace Vars
{
    internal class Program
    {
	static void Main()
	{
	    string Str = "This is a string";

	    Console.WriteLine(Str);
	    Console.Write('\n' + Str + '\n');
	    
	    UInt16 Alpha = 15;
	    Int32 Omega = -99;
	    short Zeta = -1;
	    ushort Epsylon = (ushort)Math.Abs(-5);
	    uint Theta = (uint)Math.Abs(-5);
	    long Ny = 12;

	    Console.Write("This is {0} {1} ", "The value of", "Theta" + ' ' + Theta);
	    Console.Write("\n" + (Alpha + Omega + Zeta + Epsylon + Theta + Ny) + "\n\n");
	    Console.WriteLine(Theta + Ny + "\n\n");

	    /*
	      This will give a wrong answer
	      The escape sequen \n is driven as a char
	      It return the ASCII value 10 and add it to Alpha Value
	    */
	    Console.WriteLine('\n' + Alpha);

	    //This will give the right answer
	    Console.WriteLine("\n" + Alpha);

	    //This will give a wrong answer
	    Console.WriteLine("Zeta + Ny " + Zeta + Ny);

	    //This will give the right answer
	    Console.WriteLine("Zeta + Ny " + (Zeta + Ny));

	    double MyDouble = 50.5D;
	    char MyLetter = 'B';
	    bool MyBool = true;

	    Console.Write("MyDouble Val: {0}, MyLetter Val: {1}, {2}", MyDouble, MyLetter, "MyBool Val: " + MyBool + "\n\n");
	    Console.ReadKey();
	}
    }
}
