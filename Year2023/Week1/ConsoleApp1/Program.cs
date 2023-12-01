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