#include "FileUtils.h"

/*
 * Parses through csv file line by line and returns the data
 * in vector of vector of strings.
 */
std::vector<std::vector<std::string>> CSVReader::getData() {
  std::ifstream file(fileName);
  std::vector<std::vector<std::string>> dataList;
  std::string line = "";
  std::string subline = "";

  // Iterate through each line and split the content using delimeter
  while (getline(file, line)) {
    std::vector<std::string> vec;

    std::istringstream linestream(line);
    while (getline(linestream, subline, delimeter)) {
      vec.push_back(subline);
    }

    dataList.emplace_back(vec);
  }

  // Close the File
  file.close();
  return dataList;
}
