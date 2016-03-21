#pragma once
#include "GraphMartix.h"
void importGraph(GraphMatrix<char, int> & g);
void pathPush(const std::vector<std::vector<int>> &pi, int i, int j, std::vector<int> &v);