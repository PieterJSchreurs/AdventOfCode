$wordToFind = 'XMAS'.chars
$rowsMax = 0
$columsMax = 0
$twoDArray = []
$wordsFound = 0

def read_file
  fileObject = File.open(File.dirname(__FILE__) + '/input.txt').each do |line|
    lineArray = []
    line.chars.each do |character|
      lineArray.push(character) if character != "\n"
    end
    $columnsMax = lineArray.length
    $twoDArray.push(lineArray)
  end
  $rowsMax = $twoDArray.length
end

def findWord(row, column, letterIndex, horizontal, vertical)
  return unless $twoDArray[row][column] === $wordToFind[letterIndex]

  if letterIndex === $wordToFind.length - 1
    $wordsFound += 1
  else
    # Check if last row
    return if row + horizontal >= $rowsMax || row + horizontal < 0
    return if column + vertical >= $columnsMax || column + vertical < 0

    findWord(row + horizontal, column + vertical, letterIndex + 1, horizontal, vertical)
  end
end

read_file

$twoDArray.each_with_index do |sub_array, i|
  sub_array.each_with_index do |item, j|
    findWord(i, j, 0, 1, 0)
    findWord(i, j, 0, 1, 1)
    findWord(i, j, 0, 1, -1)
    findWord(i, j, 0, -1, 0)
    findWord(i, j, 0, -1, 1)
    findWord(i, j, 0, -1, -1)
    findWord(i, j, 0, 0, 1)
    findWord(i, j, 0, 0, -1)
  end
end

puts $wordsFound
