﻿using System;

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

	    DateTime dt1, dt2;

	    dt1 = new DateTime(2003, 10, 30);
	    dt2 = DateTime.Today;
	    
	    TimeSpan Timespan = dt2.Subtract(dt1);
	    Console.WriteLine("[Dates]> dt1: {0}, dt2: {1}, timespan: {2}", dt1, dt2, Timespan.Days);

	    //Operations
	    dt = new DateTime(2022, 10, 15);
	    dt0 = new DateTime(2000, 12, 31);
	    dt1 = DateTime.Today;
	    dt2 = DateTime.UtcNow;
	    ts = new TimeSpan(20, 5, 2, 30);

	    Console.WriteLine(dt + ts);
	    Console.WriteLine(dt0 + ts);
	    Console.WriteLine(dt.Year + 5);
	    Console.WriteLine(dt > dt0);
	    Console.WriteLine(dt.Day - dt0.Day);
	    Console.WriteLine(dt2.Month + dt1.Month);
	    Console.WriteLine(dt1 < dt2);
	    Console.WriteLine(dt1 <= dt2);
	    Console.WriteLine(dt1 >= dt2);
	    Console.WriteLine(dt0 != dt2);
	    Console.WriteLine(dt1 == dt0);

	    //String convertion to DateTime
	    string Date, Time;

	    Date = "2029/7/8";
	    Time = "16:30:45";
	    DateTime.TryParse(Date, out dt);
	    var DT0 = DateTime.TryParse(Time, out dt0);

	    Console.WriteLine(Date);
	    Console.WriteLine(Time);
	    Console.WriteLine(DT0);
	    Console.WriteLine($"{dt} >> date changed here");
	    Console.WriteLine($"{dt0} >> time changed here");
	    
	    Console.ReadKey();
	}
    }
}
