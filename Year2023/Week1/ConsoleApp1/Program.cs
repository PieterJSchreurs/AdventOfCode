using System.IO;
using System.Text;

int totalNumber = 0;
int number1 = 0;
int number2 = 0;

string[] letters = new string[] { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

using (FileStream fileStream = File.Open(Path.Combine(Directory.GetCurrentDirectory(), "Input.txt"), FileMode.Open, FileAccess.Read))
{
    using (StreamReader streamReader = new StreamReader(fileStream))
    {
        while (streamReader.Peek() >= 0)
        {

            string line = streamReader.ReadLine();
            int indexStart = line.Length;
            int indexLast = 0;
            int numberfoundFirst = 0;
            int numberFoundSecond = 0;
            char[] ch = new char[line.Length];
            for (int i = 0; i < letters.Length; i++)
            {
                if (line.Contains(letters[i]))
                {
                    int index = line.IndexOf(letters[i]);
                    if (index < indexStart)
                    {
                        indexStart = index;
                        numberfoundFirst = i + 1;
                    }
                    if (numberfoundFirst != 0 && index >= indexLast)
                    {
                        indexLast = index;
                        numberFoundSecond = i + 1;
                    }
                }
            }

            for (int i = 0; i < line.Length; i++)
            {
                ch[i] = line[i];
            }
            List<int> numbersInLine = new List<int>();
            int numberToAdd = 0;
            int firstNumberDigit = 0;
            int lastNumberDigit = 0;

            foreach (char c in ch)
            {
                bool canConvert = int.TryParse(c.ToString(), out number1);
                if (canConvert)
                {
                    numbersInLine.Add(number1);
                    if (firstNumberDigit == 0)
                    {
                        firstNumberDigit = Array.IndexOf(ch, c);
                    }
                    else if (lastNumberDigit == 0)
                    {
                        lastNumberDigit = Array.IndexOf(ch, c);
                    }
                }
            }
            if (numbersInLine.Count > 0)
            {
                if (firstNumberDigit < indexStart)
                {
                    numberToAdd = numbersInLine.First() * 10;

                }
                else
                {
                    numberToAdd = numberfoundFirst * 10;

                }

                if (lastNumberDigit < indexLast)
                {
                    if (numbersInLine.Last() % 10 == 0) { numberToAdd += (numberToAdd / 10); }
                    else { numberToAdd += numbersInLine.Last(); }

                }
                else
                {
                    if (numberFoundSecond % 10 == 0) { numberToAdd += (numberToAdd / 10); }
                    else { numberToAdd += numberFoundSecond; }
                }
            }
            else
            {
                Console.WriteLine("error");
            }

            Console.WriteLine(numberToAdd);
            totalNumber += numberToAdd;



            //Console.WriteLine("\tFirst char of text has index " + indexStart + " and has a value of " + numberfoundFirst + " : " + indexLast + " / " + numberFoundSecond);
            //Console.WriteLine("Second char " + firstNumberDigit + " : " + numbersInLine.First() + ":" );
        }
    }
}
Console.WriteLine(totalNumber);


/* Part 1
using System.IO;
using System.Text;

int totalNumber = 0;
int number1 = 0;
int number2 = 0;


using (FileStream fileStream = File.Open(Path.Combine(Directory.GetCurrentDirectory(), "Input.txt"), FileMode.Open, FileAccess.Read))
{
    using(StreamReader streamReader = new StreamReader(fileStream))
    {
        while(streamReader.Peek() >= 0)
        {
            string line = streamReader.ReadLine();
            char[] ch = new char[line.Length];

            for(int i = 0; i < line.Length; i++)
            {
                ch[i] = line[i];
            }
            List<int> numbersInLine =new List<int>();
            int numberToAdd = 0;

            foreach (char c in ch)
            {
                bool canConvert = int.TryParse(c.ToString(), out number1);
                if (canConvert)
                {
                    numbersInLine.Add(number1);
                }
            }
            numberToAdd = (numbersInLine.First() * 10) + numbersInLine.Last();
            totalNumber += numberToAdd;
            Console.WriteLine(numberToAdd);
        }
    }
}
Console.WriteLine(totalNumber);
*/