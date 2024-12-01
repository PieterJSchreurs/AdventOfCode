$arrayLeft = []
$arrayRight = []
$totalDiff = 0

def read_file()
  File.open(File.dirname(__FILE__) + '/input.txt').each {
    |line| 
    lineSplit = line.split()
    $arrayLeft.push(Integer(lineSplit[0]))
    $arrayRight.push(Integer(lineSplit[1]))
  }
end

def part1()
  x = 0
  $arrayLeft = $arrayLeft.sort
  $arrayRight = $arrayRight.sort
  for i in $arrayLeft do
    difference = ($arrayLeft[x] - $arrayRight[x]).abs
    $totalDiff += difference
    x += 1
  end
end

def part2()
  $arrayLeft.each_index do |x|
    if $arrayRight.include? $arrayLeft[x]
      itemsThere = $arrayRight.select { |item| item == $arrayLeft[x]}
        $totalDiff += (itemsThere.count * $arrayLeft[x])
    end
  end
end

read_file()
# part1()
part2()
puts $totalDiff
