using System.IO;
using System.Text.RegularExpressions;

const string COLORS = @"blue|green|red";
List<string> files = new List<string>();

{
    var text = File.ReadAllLines(Path.Combine(Directory.GetCurrentDirectory(), "Input.txt"));
    files = new List<string>(text);
    Part02();
}

void Part01()
{
    int red = 0;
    int green = 0;
    int blue = 0;
    int round = 0;
    int totalPoints = 0;
    bool IsImpossible = false;
    foreach (string file in files)
    {
        IsImpossible = false;
        var splitstring = file.Split(":");
        round = Convert.ToInt32(new String(splitstring[0].Where(Char.IsDigit).ToArray()));
        var splitDraws = splitstring[1].Split(";");
        foreach (string draw in splitDraws)
        {
            var color = draw.Split(',');
            foreach (string colorDraw in color)
            {
                var whichColor = Regex.Match(colorDraw, COLORS);
                switch (whichColor.Value)
                {
                    case "blue":
                        blue = Convert.ToInt32(new String(colorDraw.Where(Char.IsDigit).ToArray()));
                        break;
                    case "red":
                        red = Convert.ToInt32(new String(colorDraw.Where(Char.IsDigit).ToArray()));
                        break;
                    case "green":
                        green = Convert.ToInt32(new String(colorDraw.Where(Char.IsDigit).ToArray()));
                        break;
                }
            }
            if (blue > 14 || green > 13 || red > 12)
            {
                IsImpossible = true;
            }
            blue = 0;
            green = 0;
            red = 0;
        }
        if (!IsImpossible)
        {
            totalPoints += round;
        }
    }
    Console.WriteLine(totalPoints);
}

void Part02()
{
    int red = 0;
    int green = 0;
    int blue = 0;
    int round = 0;
    int totalPoints = 0;
    bool IsImpossible = false;
    foreach (string file in files)
    {
        IsImpossible = false;
        var splitstring = file.Split(":");
        round = Convert.ToInt32(new String(splitstring[0].Where(Char.IsDigit).ToArray()));
        var splitDraws = splitstring[1].Split(";");
        foreach (string draw in splitDraws)
        {
            var color = draw.Split(',');
            foreach (string colorDraw in color)
            {
                var whichColor = Regex.Match(colorDraw, COLORS);
                switch (whichColor.Value)
                {
                    case "blue":
                        var Thisblue = Convert.ToInt32(new String(colorDraw.Where(Char.IsDigit).ToArray()));
                        if(Thisblue > blue)
                        {
                            blue = Thisblue;
                        }
                        break;
                    case "red":
                        var Thisred = Convert.ToInt32(new String(colorDraw.Where(Char.IsDigit).ToArray()));
                        if(Thisred > red)
                        {
                            red = Thisred;
                        }
                        break;
                    case "green":
                        var Thisgreen = Convert.ToInt32(new String(colorDraw.Where(Char.IsDigit).ToArray()));
                        if(Thisgreen> green)
                        {
                            green = Thisgreen;
                        }
                        break;
                }
            }
        }
        totalPoints += (red * blue * green);
        blue = 0;
        green = 0;
        red = 0;
    }
    Console.WriteLine(totalPoints);
}