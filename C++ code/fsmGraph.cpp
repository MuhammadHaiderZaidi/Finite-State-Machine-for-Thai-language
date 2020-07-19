#include "fsmGraph.h"


fsmGraph::fsmGraph(int numVertices):numVertices(numVertices)
{
	adjMatrix = new bool*[numVertices];
       for (int i = 0; i < numVertices; i++) {
           adjMatrix[i] = new bool[numVertices];
        }
	   for(int i=0;i<numVertices;i++)
		   for(int j=0;j<numVertices;j++)
			   adjMatrix[i][j] = false;
 }

void fsmGraph::addEdge(int i, int j)
{
        adjMatrix[i][j] = true;
}

bool fsmGraph::PrePosedVowel(wchar_t data[])
{
 		for(int j=0;j<5;j++)
		if(!wcsncmp(data,v1[j],3))
			return true;
		return false;
}
	 
bool fsmGraph::InitialConsonant(wchar_t data[])
{
 		for(int j=0;j<46;j++)
		if(!wcsncmp(data,c1[j],3))
			return true;
		return false;
}
	 
bool fsmGraph::ClusteredConsonant(wchar_t data[])
{
 		for(int j=0;j<5;j++)
		if(!wcsncmp(data,c2[j],3))
			return true;
		return false;
}
	 
bool fsmGraph::subscriptVowel(wchar_t data[])
{
 		for(int j=0;j<8;j++)
		if(!wcsncmp(data,v2[j],3))
			return true;
		return false;
}
	 
bool fsmGraph::SuperscriptMark(wchar_t data[])
{
 		for(int j=0;j<4;j++)
		if(!wcsncmp(data,t[j],3))
			return true;
		return false;
}
	 
bool fsmGraph::PostposedVowel(wchar_t data[])
{
 		for(int j=0;j<4;j++)
		if(!wcsncmp(data,v3[j],3))
			return true;
		return false;
}
	 
bool fsmGraph::FinalConsonant(wchar_t data[])
{
 		for(int j=0;j<8;j++)
		if(!wcsncmp(data,c3[j],3))
			return true;
		return false;
}

void fsmGraph::fsmTraversal(node* tempNode,int i){
//		traversing in the fsm:
		
		if(!tempNode) return;
		int j;

		for(j=0;j<numVertices;j++){
			
			if(adjMatrix[i][j]){
				if(j==0){
					if(i==7){
						tempNode=tempNode->prev;
						tempNode->sapce = true;
						break;
					}}
				if(j==1){
					if(i==8){
					tempNode=tempNode->prev;
					tempNode->prev->sapce = true;
					break;
					}
					else if(PrePosedVowel(tempNode->output)) break;}
				if(j==2){
					if(i==9){
					tempNode=tempNode->prev;
					tempNode->prev->sapce = true;
					break;}
					else if(InitialConsonant(tempNode->output)) break;}
				if(j==3)
					if(ClusteredConsonant(tempNode->output)) break;
				if(j==4)
					if(subscriptVowel(tempNode->output)) break;
				if(j==5)
					if(SuperscriptMark(tempNode->output)) break;
				if(j==6)
					if(PostposedVowel(tempNode->output)) break;
				if(j==7)
					if(FinalConsonant(tempNode->output)) break;
				if(j==8)
					if(PrePosedVowel(tempNode->output)) break;
				if(j==9)
					if(InitialConsonant(tempNode->output)) break;
			}
			if(j==numVertices-1) {j=i;break;}
		}
		
		fsmTraversal(tempNode->next,j);
}



fsmGraph::~fsmGraph(void)
{
	for (int i = 0; i < numVertices; i++)
       delete[] adjMatrix[i];
    delete[] adjMatrix;
}