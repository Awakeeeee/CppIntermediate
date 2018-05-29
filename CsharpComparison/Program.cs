using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpComparison
{
    class Program
    {
        static void Main(string[] args)
        {
            //C++ map
            Dictionary<int, string> dict = new Dictionary<int, string>();

            //C# dictionary will NOT sort the elements by key
            dict.Add(5, "dog");
            dict.Add(1, "dog");
            dict.Add(3, "dog");

            foreach(KeyValuePair<int, string> item in dict)
            {
                Console.WriteLine(item.Key.ToString() + " : " + item.Value);
            }
        }
    }
}
