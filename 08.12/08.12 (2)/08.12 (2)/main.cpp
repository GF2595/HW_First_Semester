#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct NewMinimalNodeInfo{
	int minimalEdgeLength = 2147483647;
	int minimalEdgeFinishingNode = -1;
	int minimalEdgeStartingNode = -1;
};

//Finds in graph specified by adjacency matrix node with minimal distance from visited nodes
//Receives adjacency matrix, adjacency matrix size and list of visited nodes
//Returns container including minimal edge length, node with minimal distance from visited and node with which it is connected most shortly
NewMinimalNodeInfo findNewNode(vector<vector<int>> matrix, int matrixSize, vector<int> visitedNodes)
{
	NewMinimalNodeInfo result;

	unsigned temp = visitedNodes.size();

	for (unsigned i = 0; i < temp; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrix[visitedNodes[i]][j] < result.minimalEdgeLength && matrix[visitedNodes[i]][j] != 0)
			{
				result.minimalEdgeLength = matrix[visitedNodes[i]][j];

				result.minimalEdgeFinishingNode = j;
				result.minimalEdgeStartingNode = visitedNodes[i];
			}
		}
	}

	return result;
}

//Fills specified column by 0
//Receives matrix, matrix size and number of column to be cleaned
//Returns reformed matrix
vector<vector<int>> cleanColumn(vector<vector<int>> matrix, int matrixSize, int requiredColumn)
{
	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i][requiredColumn] = 0;
	}

	return matrix;
}

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream file("../file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Файл не найден" << endl;

		return EXIT_FAILURE;
	}

	int matrixSize = 0;

	vector<vector<int>> adjacencyMatrix;
	vector<vector<int>> resultingMatrix;

	file >> matrixSize;

	for (int i = 0; i < matrixSize; i++)
	{
		vector<int> temp;
		vector<int> tempResulting;

		for (int j = 0; j < matrixSize; j++)
		{
			int tempNumber = 0;

			file >> tempNumber;

			temp.push_back(tempNumber);
			tempResulting.push_back(0);
		}

		adjacencyMatrix.push_back(temp);
		resultingMatrix.push_back(tempResulting);
	}

	file.close();

	vector<int> visitedNodes;
	visitedNodes.push_back(0);
	int counter = matrixSize - 1;

	adjacencyMatrix = cleanColumn(adjacencyMatrix, matrixSize, 0);

	while (counter > 0)
	{
		NewMinimalNodeInfo newNode = findNewNode(adjacencyMatrix, matrixSize, visitedNodes);

		if (newNode.minimalEdgeFinishingNode != -1)
		{
			adjacencyMatrix = cleanColumn(adjacencyMatrix, matrixSize, newNode.minimalEdgeFinishingNode);

			visitedNodes.push_back(newNode.minimalEdgeFinishingNode);

			resultingMatrix[newNode.minimalEdgeFinishingNode][newNode.minimalEdgeStartingNode] = newNode.minimalEdgeLength;
			resultingMatrix[newNode.minimalEdgeStartingNode][newNode.minimalEdgeFinishingNode] = newNode.minimalEdgeLength;

			counter--;
		}
	}

	cout << "Матрица смежности минимального остовного дерева: " << endl << endl;

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << resultingMatrix[i][j] << " ";
		}

		cout << endl;
	}

	return EXIT_SUCCESS;
}