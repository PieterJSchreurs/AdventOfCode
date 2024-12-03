def read_file
  fileObject = File.open(File.dirname(__FILE__) + '/input.txt')
  fileString = fileObject.read
  use_regex_part1(fileString)
end

def use_regex_part1(input)
  total = 0
  values = input.scan(/mul\((\d*),(\d*)\)/)
  values.each do |x|
    total += Integer(x[0]) * Integer(x[1])
  end
  puts total
end

def use_regex_part2(input)
  total = 0
  doActive = true
  values = input.scan(/mul\((\d*),(\d*)\)|(don't)|(do)/)
  values.each do |x|
    if !x[2].nil?
      doActive = false
      next
    elsif !x[3].nil?
      doActive = true
      next
    end
    total += Integer(x[0]) * Integer(x[1]) if doActive
  end
  puts total
end

read_file
