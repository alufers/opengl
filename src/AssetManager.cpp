#include "AssetManager.h"

AssetManager::AssetManager() {
  
}

std::string AssetManager::resolvePath(const std::string &relative, const std::string &base) {
  return boost::filesystem::canonical(boost::filesystem::path(relative), boost::filesystem::path(base)).string();
}

std::string AssetManager::loadText(std::string path) {
  std::ifstream file(path);
  std::string data((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  return data;
}

std::string AssetManager::dirname(const std::string &path) {
  return boost::filesystem::path(path).parent_path().string();
}

json AssetManager::loadJson(std::string path) {
  return json::parse(this->loadText(path));
}
