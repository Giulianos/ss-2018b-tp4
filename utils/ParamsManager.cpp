//
// Created by Giuliano Scaglioni on 06/11/2018.
//

#include "ParamsManager.h"
#include <fstream>

ParamsManager::ParamsManager(std::string filename)
  : filename(filename)
{
  std::ifstream fs(filename);
  std::string temp_line;
  while (std::getline(fs, temp_line)) {
    size_t delimiter_position = temp_line.find("=");
    std::string key = temp_line.substr(0, delimiter_position);
    std::string value =
      temp_line.substr(delimiter_position + 1, temp_line.size() - 1);
    params.insert(std::make_pair(key, value));
    fprintf(stderr,
            "Inserted parameter into map: {%s, %s}\n",
            key.c_str(),
            value.c_str());
  }
}

std::string
ParamsManager::get(const std::string key) const
{
  return params.at(key);
}
