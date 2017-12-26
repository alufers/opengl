#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include "ShaderProgram.h"
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <mpark/variant.hpp>
#include <streambuf>
#include <string>
using json = nlohmann::json;

class ShaderProgram;
typedef mpark::variant<std::string, ShaderProgram> assetType;
class AssetManager {
public:
  std::string resolvePath(const std::string &relative, const std::string &base);
  std::string dirname(const std::string &path);
  std::string loadText(std::string path);
  json loadJson(std::string json);
  AssetManager();
  AssetManager(const AssetManager &) = delete;
  AssetManager &operator=(const AssetManager &) = delete;
};
#endif
