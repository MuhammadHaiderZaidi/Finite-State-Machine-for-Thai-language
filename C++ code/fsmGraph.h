#pragma once
#include "DLLInput.h"
#include <wchar.h>

class fsmGraph
{
private:

	bool** adjMatrix;
    int numVertices;

public:

	wchar_t v1 [5][3];
	wchar_t c1 [46][3];
	wchar_t c2 [5][3];
	wchar_t v2 [8][3];
	wchar_t t [4][3];
	wchar_t v3 [4][3];
	wchar_t c3 [8][3];

private:

	bool PrePosedVowel(wchar_t []);
	bool InitialConsonant(wchar_t []);
	bool ClusteredConsonant(wchar_t []);
	bool subscriptVowel(wchar_t []);
	bool SuperscriptMark(wchar_t []);
	bool PostposedVowel(wchar_t []);
	bool FinalConsonant(wchar_t []);

public:
	fsmGraph(int);
	void addEdge(int, int);
	~fsmGraph(void);
	void fsmTraversal(node*,int);
};

