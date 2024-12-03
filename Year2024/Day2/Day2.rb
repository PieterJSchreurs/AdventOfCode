def is_safe(array)
  previousValue = 0
  increasing = false
  decreasing = false
  array.each do |value|
    if previousValue === 0
    else
      if previousValue < value
        increasing = true
        puts 'increasing'
      elsif previousValue > value
        decreasing = true
        puts 'decreasing'
      end
      return false if previousValue === value
      return false if decreasing && increasing

      if increasing
        return false unless value.between?(previousValue, previousValue + 3)

      elsif decreasing
        return false unless value.between?(previousValue - 3, previousValue)
      end
    end
    previousValue = value
  end
  puts 'This one matches'
  true
end

def is_safe_part2?(line)
  is_sorted?(line) && within_tolerance?(line)
end

def within_tolerance?(line)
  line.each_with_index do |value, index|
    next if index == 0

    difference = (value - line[index - 1]).abs
    return false if difference > 3 || difference == 0
  end
  true
end

def is_sorted?(line)
  if (line == line.sort) || (line.reverse == line.sort)
    true
  else
    false
  end
end

def read_file
  $trueCounts = 0
  $arrayLine = []
  File.open(File.dirname(__FILE__) + '/input.txt').each do |line|
    lineSplit = line.split
    puts line
    $arrayLine.push(lineSplit.grep(/\d+/, &:to_i))
  end
end

read_file

$arrayLine.each do |measurement|
  if is_safe_part2?(measurement)
    $trueCounts += 1
  else
    measurement.combination(measurement.length - 1).each do |combination|
      if is_safe_part2?(combination)
        $trueCounts += 1
        break
      end
    end
  end
end

puts $trueCounts
