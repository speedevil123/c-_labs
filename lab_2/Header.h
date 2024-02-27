#pragma once
#include <iostream>
#include <string>

std::string* readArray(std::string path, int& num);
void printArray(std::ostream& out, std::string* arr, int num);
std::string* getwords(std::string* arr, int& size);
void writeResult(std::ostream& out, std::string* words, int num);
