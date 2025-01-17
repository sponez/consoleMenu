﻿#include <iostream>
#include <vector>
#include "wconsoleMenu.h"

using namespace std;

void emptyFunc(wstring str)
{
	wcout << str << endl;
	_wsystem(L"pause");
}
void toBranch(wstring);

vector<wstring> options = { L"Один" , L"Два" };
vector<void (*)(wstring)> funcsRoot({ toBranch, [](wstring) {} });

wconsoleMenu root(options, funcsRoot);
wconsoleMenu branch;

void toBranch(wstring) { branch.cyclicSelect(); }

int main()
{
	vector<void (*)(wstring)> branchFuncs = { emptyFunc , emptyFunc };
	branch = wconsoleMenu(options, branchFuncs, L"", L"Назад");
	wcout << root.singleSelectWithFilter() << endl;
}