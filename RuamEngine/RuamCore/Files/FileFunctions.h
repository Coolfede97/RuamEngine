#pragma once

#include <string>

#include <fstream>
#include <sstream>
#include <iostream>

std::string FileToString(const std::string& absoluteFilePath);

std::string ProjectFileToString(const std::string& relativeFilePath);