#include "DLLInput.h"
#include "fsmGraph.h"
#include<fcntl.h>
#include<io.h>

using namespace std;



 int main(){
 	
	 _setmode(_fileno(stdout),_O_U16TEXT);


	
	wchar_t input [100][300];
	wchar_t output[100][300];

	FILE * chkFile;
	chkFile = fopen ("compare.txt" , "r");
   if (chkFile != NULL)
   {
	  int count = 0;
     while ( count!=7 )
		 fgetws (input[count++] , 300 , chkFile) ;
     fclose (chkFile);
   }


   fsmGraph thaiFsm(10);


   thaiFsm.addEdge(0,1);
   thaiFsm.addEdge(0,2);
   thaiFsm.addEdge(1,2);
   thaiFsm.addEdge(2,3);
   thaiFsm.addEdge(2,4);
   thaiFsm.addEdge(2,5);
   thaiFsm.addEdge(2,6);
   thaiFsm.addEdge(2,7);
   thaiFsm.addEdge(2,8);
   thaiFsm.addEdge(2,9);
   thaiFsm.addEdge(3,4);
   thaiFsm.addEdge(3,6);
   thaiFsm.addEdge(3,7);
   thaiFsm.addEdge(3,8);
   thaiFsm.addEdge(4,5);
   thaiFsm.addEdge(4,6);
   thaiFsm.addEdge(4,7);
   thaiFsm.addEdge(4,8);
   thaiFsm.addEdge(4,9);
   thaiFsm.addEdge(5,6);
   thaiFsm.addEdge(5,7);
   thaiFsm.addEdge(5,8);
   thaiFsm.addEdge(5,9);
   thaiFsm.addEdge(6,7);
   thaiFsm.addEdge(6,8);
   thaiFsm.addEdge(6,9);
   thaiFsm.addEdge(7,0);
   thaiFsm.addEdge(8,1);
   thaiFsm.addEdge(9,2);


   for(int i=0;i<8;i++)
	   for(int j=0;j<3;j++)
		   thaiFsm.c3[i][j] = input[6][(i*3)+j];

   for(int i=0;i<5;i++)
	   for(int j=0;j<3;j++)
		   thaiFsm.c2[i][j] = input[2][(i*3)+j];

   for(int i=0;i<5;i++)
	   for(int j=0;j<3;j++)
		   thaiFsm.v1[i][j] = input[0][(i*3)+j];

	for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
			thaiFsm.t[i][j] = input[4][(i*6)+3+j];

	for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
			thaiFsm.v3[i][j] = input[5][(i*3)+j];

	for(int i=0;i<8;i++)
		for(int j=0;j<3;j++)
			thaiFsm.v2[i][j] = input[3][(i*6)+3+j];

	for(int i=0;i<46;i++)
		for(int j=0;j<3;j++)
			thaiFsm.c1[i][j] = input[1][(i*3)+j];


   FILE * pFile;
   int count = 0;
   pFile = fopen ("fsm_input.txt" , "r");
   if (pFile != NULL)
   {
	
	 while(!feof(pFile))
		 fgetws (input[count++] , 300 , chkFile);

	 fclose(pFile);
   }

   int index1=0;
   while(index1<count){
   DLLInput thai;
   for(int i=0;i<wcslen(input[index1]);i++){
	wchar_t tempData[3];
	   for(int j=0;j<3;j++)
		   tempData[j] = input[index1][(i*3)+j];
	   
	thai.addNode(tempData);
   }

   thaiFsm.fsmTraversal(thai.getHead(),0);

   
   int index = 0;
   node* tempNode = thai.getHead();
   while(tempNode){
	   wchar_t* tempData = thai.getData(tempNode);
	   for(int i=0;i<3;i++)
		   output[index1][index++] = tempData[i];
	   if(thai.isSpace(tempNode)) output[index1][index++] = ' ';
	   tempNode = tempNode->next;
   }
   index1++;
   }
   //fwprintf (stdout, L" ");



   // OUTPUT
   FILE * oFile;

   oFile = fopen ("fsm_output.txt" , "w");
   
   int i = 0;
   while(i<count)
   fputws ( output[i++], oFile );
   
     fclose (oFile);

	
	return 0;

 }