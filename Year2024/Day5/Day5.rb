$indexArray = []
$numbersArray = []
$resultTotal = 0

def read_file
  fileObject = File.open(File.dirname(__FILE__) + '/input.txt').each do |line|
    if line.include?('|')
      splitString = line.split('|')
      splitString.each_with_index do |chars, i|
        splitString[i] = chars.strip
      end
      $indexArray.push(splitString)
    elsif line.include?(',')
      splitString = line.split(',')
      splitString.each_with_index do |chars, i|
        splitString[i] = chars.strip
      end
      $numbersArray.push(splitString)
    end
  end
end

def hasBothNumbers(numberOne, numberTwo)
  returnValue = false
  $indexArray.each do |number|
    return true if returnValue

    returnValue = number[0] === (numberOne) && number[1] === numberTwo
  end
  returnValue
end

def arrayContainsAnyPair(inputArray)
  inputArray.each_with_index do |inputRow, index|
    totalMatches = 0
    correctMatches = 0
    inputRow.each_with_index do |number, j|
      for k in 0..number.length do
        next if j == k

        containsBoth = hasBothNumbers(number, inputRow[k])
        next unless containsBoth

        totalMatches += 1

        correctMatches += 1 if isValid(number, inputRow[k], inputRow)

      end
    end
    $resultTotal += Integer(findMiddlePageFromRow(index)) if totalMatches === correctMatches
  end
end

def isValid(numberOne, numberTwo, numberArray)
  numberArray.find_index(numberOne) < numberArray.find_index(numberTwo)
end

def findMiddlePageFromRow(rowNumber)
  rowNumberInt = Integer(rowNumber)
  rowSize = $numbersArray[rowNumberInt].length
  $numbersArray[rowNumberInt][rowSize / 2]
end

read_file
arrayContainsAnyPair($numbersArray)
puts $resultTotal
