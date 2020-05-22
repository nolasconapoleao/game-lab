#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

/*
 * A class to read data from a csv file.
 */
class CSVReader {
  std::string fileName;
  char delimeter;

public:
  CSVReader(std::string filename, char delm = ';') : fileName(filename), delimeter(delm) {
  }

  // Function to fetch data from a CSV File
  std::vector<std::vector<std::string>> getData();
};
