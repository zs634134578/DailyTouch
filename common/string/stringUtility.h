#pragma once

#include <string>
#include <vector>

std::string ToString(int num);

void SplitToVec(const std::string& str,
                const std::string& boundary,
                std::vector<std::string>& strVec);
