#include "AssetManager.h"

std::string AssetManager::loadText(std::string path) {
  std::ifstream file(path);
  std::string data((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  return data;
}
