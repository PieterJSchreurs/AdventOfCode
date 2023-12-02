using System.IO;
using System.Text;
using System.Text.RegularExpressions;

int sum = 0;
const string DIGIT_PATTERN = @"one|two|three|four|five|six|seven|eight|nine|[0-9]";

using (FileStream fileStream = File.Open(Path.Combine(Directory.GetCurrentDirectory(), "Input.txt"), FileMode.Open, FileAccess.Read))
{
    using (StreamReader streamReader = new StreamReader(fileStream))
    {
        while (streamReader.Peek() >= 0)
        {
            string line = streamReader.ReadLine();
            var first = Regex.Match(line, DIGIT_PATTERN);
            var last = Regex.Match(line, DIGIT_PATTERN, RegexOptions.RightToLeft);
            sum += 10 * GetValue(first.Value) + GetValue(last.Value);
        }

        Console.WriteLine(sum);
    }
}

static int GetValue(string s)
{
    return s switch
    {
        "one" => 1,
        "two" => 2,
        "three" => 3,
        "four" => 4,
        "five" => 5,
        "six" => 6,
        "seven" => 7,
        "eight" => 8,
        "nine" => 9,
        _ => int.Parse(s)
    };
}


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