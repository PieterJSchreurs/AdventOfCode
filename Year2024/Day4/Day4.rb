$wordToFind = 'XMAS'.chars
$wordToFindPart2 = 'MAS'.chars
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
  # return unless $twoDArray[row][column] === $wordToFind[letterIndex]
  return false unless $twoDArray[row][column] === $wordToFind[letterIndex]

  # if letterIndex === $wordToFind.length - 1
  return true if letterIndex === $wordToFind.length - 1

  # Check if last row or column
  return false if row + horizontal >= $rowsMax || row + horizontal < 0
  return false if column + vertical >= $columnsMax || column + vertical < 0

  findWord(row + horizontal, column + vertical, letterIndex + 1, horizontal, vertical)
end

def findWordPart2(row, column, letterIndex, horizontal, vertical)
  return false if letterIndex != 1

  # Check if new pos is an M or S
  isM = findLetterForPosition(row + horizontal, column + vertical, 0)
  isS = findLetterForPosition(row + horizontal, column + vertical, 2)

  if isM
    otherIsS = findLetterForPosition(row - horizontal, column - vertical, 2)
    return true if otherIsS
  end
  if isS
    otherIsM = findLetterForPosition(row - horizontal, column - vertical, 0)
    return true if otherIsM
  end
  false
end

def findLetterForPosition(row, column, letterIndex)
  return false if row >= $rowsMax || row < 0

  return false if column >= $columnsMax || column < 0

  $twoDArray[row][column] === $wordToFindPart2[letterIndex]
end

read_file

$twoDArray.each_with_index do |sub_array, i|
  sub_array.each_with_index do |item, j|
    # findWord(i, j, 0, 1, 0)
    # findWord(i, j, 0, 1, 1)
    # findWord(i, j, 0, 1, -1)
    # findWord(i, j, 0, -1, 0)
    # findWord(i, j, 0, -1, 1)
    # findWord(i, j, 0, -1, -1)
    # findWord(i, j, 0, 0, 1)
    # findWord(i, j, 0, 0, -1)
    next unless $twoDArray[i][j] === $wordToFindPart2[1]

    trueCounts = 0
    trueCounts += 1 if findWordPart2(i, j, 1, 1, 1)
    trueCounts += 1 if findWordPart2(i, j, 1, 1, -1)

    $wordsFound += 1 if trueCounts >= 2
  end
end

puts $wordsFound
