#include "iostream"
#include "fstream"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
bool visited[9];

int** ReadAdjacencyMatrix(string filename, int& n) {
	int** adjMat = NULL;
	ifstream fin(filename);
	if (!fin) {
		cout << endl << "Cant open " << filename;
		return adjMat;
	}
	cout << endl << "Opened " << filename << endl;
	fin >> n;
	adjMat = new int* [n];
	for (int i = 0; i < n; i++) {
		adjMat[i] = new int[n];
		for (int j = 0; j < n; j++) {
			fin >> adjMat[i][j];
		}
	}
	return adjMat;
}
int** ReadAdjacencyList(string filename, int& n) {
	int** adjMat = NULL;
	ifstream fin(filename);
	if (!fin) {
		cout << endl << "Cant open " << filename;
		return adjMat;
	}
	cout << endl << "Opened " << filename << endl;
	string temp;
	getline(fin, temp, '\n');
	n = stoi(temp);
	adjMat = new int* [n];
	int adjVer[9] = { 0 }; // Adjacent vertices;
	for (int i = 0; i < n; i++) {
		adjMat[i] = new int[n];
		string line;
		getline(fin, line, '\n');
		stringstream s(line);
		string buffer;
		while (!s.eof()) {
			getline(s, buffer, ' ');
			if (buffer != "") {
				int vertice = stoi(buffer);
				adjVer[vertice] = 1;
				cout << endl << vertice;
			}
		}
		for (int j = 0; j < n; j++) {
			adjMat[i][j] = adjVer[j];
		}
		memset(adjMat, 0, 9 * sizeof(int));
	}
	return adjMat;
}
vector<int>* ConvMatrixToList(int** a, int n) { //The vertice number
	vector <int>* adj = new vector<int>[n];
	//int a[n], int* a=new int[n]
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1)
				adj[i].push_back(j);
		}
	}
	return adj;
}
void printMatrix(int** a, int n) {
	cout << endl << "PRINT" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
bool IsUndirectedGraph(int** a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] != a[j][i])
				return false;
		}
	}
	return true;
}
int* DegreeOfEachVertices(int** a, int n) { //Undirected Graph
	int* degreeVertice = new int[n]{0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			degreeVertice[i] += a[i][j];
		}
	}
	return degreeVertice;
}
int* InDegree(int** a, int n) {
	int* inDegree = new int[n]{0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			inDegree[i] += a[j][i];
		}
	}
	return inDegree;
}
int* Degree(int** a, int n) {
	int* outDegree = new int[n] {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			outDegree[i] += a[i][j];
		}
	}
	return outDegree;
}

void FreeMatrix(int**& a, int  n) {
	for (int i = 0; i < n; i++) {
		delete[]a[i];
		a[i] = NULL;
	}
	delete[]a;
	a = NULL;
}
void DFS(int u,vector<int>* adj) { //Vist vertice u
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]) {
		if (visited[v] == false)
			DFS(v, adj);
	}

}
int main() {
	int n;
	int** a = ReadAdjacencyList("graph2.txt",n);
	printMatrix(a, n);
	memset(visited, false, sizeof(visited));

	FreeMatrix(a, n);
}