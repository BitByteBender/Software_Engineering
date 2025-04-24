using System;

namespace ClsImplementation
{
    class clsStudents
    {
	    //private string Name = "";
	    private sbyte Age = 0;

	    public void SetAge(sbyte Years)
	    {
		this.Age = Years;
	    }
	    
	    public sbyte CalcAge(sbyte Years)
	    {
		return ((sbyte)(this.Age * Years));
	    }

	    public sbyte GetAge()
	    {
		return (Age);
	    }
    };

    class clsA
    {
	public string m_Name = "";
	public static sbyte m_Value = 0, X = 55;
	public sbyte Y = 45;

	public void SetName(string Name)
	{
	    this.m_Name = Name;
	}

	public static sbyte CalcValue(sbyte A, sbyte B)
	{
	    return ((sbyte)(m_Value + A + B));
	}

	public static sbyte Calc()
	{
	    return ((sbyte)(X + clsA.Y));
	}
    };
    
    internal class Program
    {

	public static void Main(string [] args)
	{
	    Console.WriteLine("Hello");
	    
	    clsStudents st1 = new clsStudents();
	    st1.SetAge(5);
	    sbyte NA = st1.CalcAge(5);

	    Console.WriteLine("Age: {0}, New Age: {1}", st1.GetAge(), NA);

	    Console.Write("\n\n");

	    clsA cA = new clsA();
	    string NewName1, NewName2;
	    
	    cA.m_Name = "Souf";
	    clsA.m_Value = 15;
	    NewName1 = cA.m_Name;
	    
	    cA.SetName("Sdg");
	    sbyte NewVal = clsA.CalcValue(15, 5), Xval = clsA.Calc();
	    
	    NewName2 = cA.m_Name;

	    Console.WriteLine("cName: {0}, N1: {1}, N2: {2}, Val: {3}, Static Method Val: {4}, Calc: {5}", cA.m_Name, NewName1, NewName2, clsA.m_Value, NewVal, Xval);
	    
	    Console.ReadKey();
	}
    }
}
