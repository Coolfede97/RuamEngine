#pragma once

#include <string>

#include <fstream>
#include <sstream>
#include <iostream>

std::string FileToString(const std::string& absoluteFilePath);

std::string RelativeFileToString(const std::string& relativeFilePath);

std::string GlobalizePath(const std::string& relativeFilePath);