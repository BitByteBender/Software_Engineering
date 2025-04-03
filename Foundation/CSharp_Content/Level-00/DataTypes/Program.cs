using System;

namespace DataTypes
{
    internal class Program
    {
	enum enOperations {Yes = 0, No = 1, Exit = 2};
	enum enBrands : sbyte {RR, B, Rarri, Lambo};
	enum enGreekAlpbet {Omega = 'O', Theta = 'T'};

	struct stStudent
	{
	    public sbyte Id = default(sbyte), Age = 0;
	    public string Name = "", SchoolName = "";

	    public stStudent(sbyte id, sbyte age, string name, string sn)
	    {
		this.Id = id;
		this.Age = age;
		this.Name = name;
		this.SchoolName = sn;
	    }
	};

	struct stStudentX
	{
	    public sbyte Id, Age;
	    public string Name, SchoolName;
	};
	
	static void Main()
	{
	    byte ValX = 8;
	    sbyte ValY = 8;
	    Int16 ValA = 16;
	    Int32 ValB = 32;
	    UInt16 ValC = 016;
	    UInt32 ValD = 032;
	    long ValE = 64L;
	    ulong ValF = 64UL;

	    string Format = "";
	    
	    Format = "byte: {0}, sbyte(Unsigned): {1}, Int16: {2}, Int32: {3}, ";
	    Format += "Int32: {4}, UInt32: {5}, long: {6}, ULong: {7}";
	    
	    Console.WriteLine(Format, ValX, ValY, ValA, ValB, ValC, ValD, ValE, ValF);

	    float Flt = 15.2f;
	    double Dbl = 52.85d;
	    decimal Dec = 0.15e3M;
	    char Char = default(char);
	    bool Bool = default(bool);
	    
	    Format = "float: {0}, double: {1}, decimal: {2}, char: {3}, bool: {4}";
	    Console.WriteLine(Format, Flt, Dbl, Dec, Char, Bool);

	    Format = "[{0}]> Min: {1} | Max: {2}\n";
	    Console.Write(Format, "int", int.MinValue, int.MaxValue);
	    Console.Write(Format, "short", short.MinValue, short.MaxValue);
	    Console.Write(Format, "Int16", Int16.MinValue, Int16.MaxValue);
	    Console.Write(Format, "Int32", Int32.MinValue, Int32.MaxValue);
	    Console.Write(Format, "UInt16", UInt16.MinValue, UInt16.MaxValue);
	    Console.Write(Format, "UInt32", UInt32.MinValue, UInt32.MaxValue);
	    Console.Write(Format, "long", long.MinValue, long.MaxValue);
	    Console.Write(Format, "ulong", ulong.MinValue, ulong.MaxValue);
	    Console.Write(Format, "float", float.MinValue, float.MaxValue);
	    Console.Write(Format, "double", double.MinValue, double.MaxValue);
	    Console.Write(Format, "decimal", decimal.MinValue, decimal.MaxValue);
	    Console.Write(Format, "char", char.MinValue, char.MaxValue);
	    
	    Console.WriteLine("\n1st: {0}, 2nd: {1}, 3rd: {2}", enOperations.Yes, enOperations.No, enOperations.Exit);
	    Console.Write("[Brands]> {" + enBrands.RR + ", " + enBrands.B + ", " + enBrands.Rarri + ", " + enBrands.Lambo + "}\n");

	    enGreekAlpbet GA, GAOm, GATh;
	    GA = enGreekAlpbet.Omega;

	    Console.Write("[Greek Alpbet]> {0}", GA + "\n\n");

	    char Answer = 'T';
	    GAOm = GA;
	    GATh = enGreekAlpbet.Theta;
	    if (Answer == (char)enGreekAlpbet.Omega)
		Console.WriteLine("this is " + GAOm);
	    else if (Answer == (char)GATh)
		Console.Write("\nThis is {0}\n", GATh);
	    else
		Console.WriteLine("No greek alphabet aligns with the answer\n");
	    
	    Answer = 'O';
	    if ((enGreekAlpbet)Answer == enGreekAlpbet.Omega)
		Console.WriteLine("this is " + GAOm);
	    else if ((enGreekAlpbet)Answer == GATh)
		Console.Write("\nThis is {0}\n", GATh);
	    else
		Console.WriteLine("No greek alphabet aligns with the answer\n");

	    //Nullable Types
	    Nullable<Int16> X = null;
	    Console.WriteLine(X);

	    X = 2550;
	    Console.WriteLine(X);

	    //Anonymous Type (Read-Only)
	    var Student = new {Id = 5, Name = "Souf", Age = 15};
	    Console.Write("Id: " + Student.Id + "\n");
	    Console.Write("Name: {0}\n", Student.Name);
	    Console.Write("Age: {0}", Student.Age + "\n");

	    Console.WriteLine(Student);

	    var StudentX = new {
		Id = 1,
		Name = "SS",
		Age = 87,
		StudentA = new {Id = default(UInt16), Name = "SJW", Age = 21},
	    };
	    
	    Console.Write("Id: " + StudentX.Id + "\n");
	    Console.Write("Name: {0}\n", StudentX.Name);
	    Console.Write("Age: {0}", StudentX.Age + "\n");
	    Console.Write("SA Id: " + StudentX.StudentA.Id + "\n");
	    Console.Write("SA Name: {0}\n", StudentX.StudentA.Name);
	    Console.Write("SA Age: {0}", StudentX.StudentA.Age + "\n");
	    
	    Console.WriteLine(StudentX);
	    Console.WriteLine(StudentX.StudentA);

	    /*
	      Struct:
	      -> If Fields(Members):
	         - are assigned a value it needs a constructor
	         - Not assigned a value we could use the 'new' keyword
		   to instantiate an empty struct object
		 - object values can be fed data or kept empty
	      -> Using the 'new' keyword does not mean it is allocated in the heap
	         since it is not a member of a class
	    */
	    stStudent Student1;

	    Console.Write("Id: {0}, ", (Student1.Id = 1));
	    Console.Write("Age: {0}, ", (Student1.Age = 17));
	    Console.Write("Name: {0}, ", (Student1.Name = "SJW Hunter"));
	    Console.Write("SchoolName: " + (Student1.SchoolName = "Solo") + "\n");

	    stStudentX Student2 = new stStudentX(), Student3 = new stStudentX();

	    Console.Write("Id: <{0}>, ", (Student2.Id = 2));
	    Console.Write("Age: <{0}>, ", (Student2.Age = 22));
	    Console.Write("Name: <{0}>, ", (Student2.Name = "SS SS"));
	    Console.Write("SchoolName: <" + (Student2.SchoolName = "Holberton School") + ">\n");

	    Console.Write("Id: <{0}>, ", (Student3.Id));
	    Console.Write("Age: <{0}>, ", (Student3.Age));
	    Console.Write("Name: <{0}>, ", (Student3.Name));
	    Console.Write("SchoolName: <" + (Student3.SchoolName) + ">\n");

	    Student3.Id = 1;
	    Student3.Age = 30;
	    Student3.Name = "Souf Sdg";
	    Student3.SchoolName = "Erable";
	    
	    Console.Write("Id: <{0}>, ", (Student3.Id));
	    Console.Write("Age: <{0}>, ", (Student3.Age));
	    Console.Write("Name: <{0}>, ", (Student3.Name));
	    Console.Write("SchoolName: <" + (Student3.SchoolName) + ">\n");

	    Console.Write(Student1 + "\n");
	    Console.Write(Student2 + "\n");
	    Console.Write(Student3 + "\n");
	    
	    Console.ReadKey();
	}
    }
}
