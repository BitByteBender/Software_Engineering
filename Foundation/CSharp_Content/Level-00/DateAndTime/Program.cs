using System;

namespace DateAndtime
{
    internal class Program
    {
	static void Main()
	{
	    DateTime dt;

	    dt = new DateTime(); //default
	    Console.WriteLine(dt);

	    dt = new DateTime(2025, 04, 03);
	    Console.WriteLine(dt);

	    dt = new DateTime(2025, 04, 03, 11, 38, 00);
	    Console.WriteLine(dt);

	    dt = new DateTime(2025, 04, 03, 13, 38, 20, DateTimeKind.Utc);
	    Console.WriteLine(dt);

	    //Ticks Min | Max
	    Console.Write("[Ticks]> Min: {0}, Max: {1}\n", DateTime.MinValue.Ticks, DateTime.MaxValue.Ticks);

	    //Important Methods
	    dt = new DateTime();
	    dt = DateTime.Today;
	    Console.WriteLine("Today\'s Date: " + dt);

	    dt = DateTime.UtcNow;
	    Console.WriteLine("Today\'s Date and time in UTC: " + dt);

	    dt = DateTime.Now;
	    Console.WriteLine("Today\'s Date and Time: {0}", dt);

	    Console.Write("Day: {0}, ", dt.Day);
	    Console.Write("Month: {0}, ", dt.Month);
	    Console.Write("Year: {0}\n", dt.Year);

	    Console.Write("Hour: {0}, ", dt.Hour);
	    Console.Write("Min: {0}, ", dt.Minute);
	    Console.Write("Sec: {0}\n", dt.Second);

	    //TimeSpan
	    dt = new DateTime(2222, 10, 25);
	    TimeSpan ts = new TimeSpan(2, 15, 23);

	    Console.Write(ts + "\n");
	    Console.Write("Days: {0}, ", ts.Days);
	    Console.Write("Hours: {0}, ", ts.Hours);
	    Console.Write("Mins: {0}, ", ts.Minutes);
	    Console.Write("Secs: {0}\n", ts.Seconds);

	    DateTime dt0 = dt.Add(ts);
	    Console.Write(dt0 + "\n");
	    
	    Console.ReadKey();
	}
    }
}
