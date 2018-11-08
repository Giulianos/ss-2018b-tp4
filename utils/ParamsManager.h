//
// Created by Giuliano Scaglioni on 06/11/2018.
//

#ifndef SS_TP4_PARAMSMANAGER_H
#define SS_TP4_PARAMSMANAGER_H

#include <map>
#include <string>

class ParamsManager
{
  std::map<std::string, std::string> params;
  std::string filename;

public:
  ParamsManager(std::string filename);
  std::string get(const std::string key) const;
};

#endif // SS_TP4_PARAMSMANAGER_H
