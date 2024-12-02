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

def read_file
  $trueCounts = 0
  File.open(File.dirname(__FILE__) + '/input.txt').each do |line|
    lineSplit = line.split
    puts line
    $trueCounts += 1 if is_safe(lineSplit.grep(/\d+/, &:to_i))
  end
end

read_file
puts $trueCounts
