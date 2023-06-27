using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UniAlgorithms
{
    internal class Program
    {
        static void Swap(ref int a, ref int b)
        {
            int pom = a;
            a = b;
            b = pom;
        }


        static void Main(string[] args)
        {
            int[] pole = { 9, 1, 8, 0, 2, 6, 7, 3 };
            List<int> TooToo = new List<int>();

            int p = 0, r = pole.Length, q = r/2;

            do
            {
                for (int i = 1, j = q; i < q && j < pole.Length; i++, j++)
                {
                    if (pole[i] < pole[i - 1])
                    {
                        Swap(ref pole[i], ref pole[i - 1]);
                    }

                    if (pole[j] < pole[j - 1])
                    {
                        Swap(ref pole[j], ref pole[j - 1]);
                    }
                }

                p++;
            }
            while (p < q);

            for (int i = 0, j = q; j < pole.Length; )
            {
                if (pole[i] < pole[j])
                {
                    TooToo.Add(pole[i]);
                    i++;
                }
                if (pole[i] > pole[j])
                {
                    TooToo.Add(pole[j]);
                    j++;
                }
            }

            for (int i = 0; i < TooToo.Count; i++)
            {
                Console.Write($"{TooToo[i]}\t");
            }

            Console.ReadLine();
        }
    }
}
