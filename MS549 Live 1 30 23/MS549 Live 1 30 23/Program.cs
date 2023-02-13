using System;

using System.Collections;


namespace MS549_Live_1_30_23
{
    class Program
    {
        static void Main(string[] args)
        {

            Hashtable HT1 = new Hashtable();
            HT1.Add("Race32", "sprint class - palm springs");
            HT1.Add("Race19", "Lake Michigan Triathalon");
            HT1.Add("NewRace 44", "Maui Ironman");

            Console.WriteLine("output of HT1");

            foreach (DictionaryEntry val in HT1)
            {
                Console.WriteLine("{0} and {1}) ", val.Key, val.Value);
            }
            HT1.Remove("Race19");
            Console.WriteLine("output of HT1 after remove");

            foreach (DictionaryEntry val in HT1)
            {
                Console.WriteLine("{0} and {1}) ", val.Key, val.Value);
            }

            if (HT1.ContainsValue("NewRace 44"))
                Console.WriteLine("found");
            else
                Console.WriteLine("NOT found");


            Hashtable HT2 = new Hashtable() { { "Repeat79", "NYNY Marathon" }, { "Midwest44", "Bike Iowa" } };



            Console.WriteLine("output of HT2");

            foreach (DictionaryEntry val in HT2)
            {
                Console.WriteLine("{0} and {1}) ", val.Key, val.Value);
            }

        }
    }
}
