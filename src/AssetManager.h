#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include <fstream>
#include <streambuf>
#include <string>

class AssetManager {
public:
  std::string loadText(std::string path);
};
#endif
