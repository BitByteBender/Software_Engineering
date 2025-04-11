using System;

namespace Operators
{
    internal class Program
    {
	static void Main()
	{
	    //Left Shifting
	    byte A = 55;
	    byte B = (byte)(A << 3);
	    
	    Console.WriteLine("A = {0} is left shifted by: {1} = {2}", A, 3, B);

	    A = 55;
	    B = (byte)(A << 5);
	    
	    Console.WriteLine("A = {0} is right shifted by: {1} = {2}", A, 5, B);

	    //Right Shifting
	    short X = 77;
	    short Y = (short)(X << 5);
	    
	    Console.WriteLine("X = {0} is right shifted by: {1} = {2}", X, 5, Y);

	    /*
	      Bitwise AND
	      -> 1 AND 0 is 0 (True AND False is False)
	      -> 1 AND 1 is 1 (True AND True is True)
	      -> 0 AND 0 is 0 (False AND False is False)
	      Example:  10101101
	              &
	                11001010
		      = 10001000
	    */
	    Console.WriteLine("X: {0} AND Y: {1} = {2}", X, Y, (X & Y));
	    
	    /*
	      Bitwise OR
	      -> 1 OR 0 is 1 (True OR False is True)
	      -> 1 OR 1 is 1 (True OR True is True)
	      -> 0 OR 0 is 0 (False OR False is False)
	      Example:  10101101
	              |
	                11001010
		      = 11101111
	    */
	    Console.WriteLine("X: {0} OR Y: {1} = {2}", X, Y, (X | Y));

	    /*
	      Bitwise XOR
	      -> 1 XOR 0 is 1 (True XOR False is True)
	      -> 1 XOR 1 is 0 (True XOR True is False)
	      -> 0 XOR 1 is 1 (False XOR True is True)
	      -> 0 XOR 0 is 0 (False XOR False is False)
	      -> Whenever 2 different digits like:
	         0 XOR 1 - 1 XOR 0 will always be 1 (True)
	      Example:  10101101
	              ^
	                11001010
		      = 01100111
	    */
	    Console.WriteLine("X: {0} XOR Y: {1} = {2}", X, Y, (X ^ Y));


	    /*
	      Lambda Expression using Anonymous function =>
	    */

	    var Str = (string A) => A + " Test";
	    Console.WriteLine(Str("This is a "));

	    var AddNums = (int X, int Y) => X + Y;
	    Int16 Sum = (short)AddNums(5, 5);
	    Console.WriteLine(Sum);

	    //Unary Operators
	    X = 15;
	    Console.WriteLine((+X));

	    X = 16;
	    Console.WriteLine((-X));
	    
	    Console.ReadKey();
	}
    }
}
