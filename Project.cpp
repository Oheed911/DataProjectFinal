
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//implementation of queue
template<class T>
struct Queue
{
	T data;
	Queue<T>* next;

};


template<class T>
struct tunnel
{
public:
	Queue<T>* front;
	Queue<T>* rear;
	int size = 0;
	tunnel()
	{
		front = NULL;
		rear = NULL;
	}
	//function to get front
	void enqueue(T a1)
	{
		Queue<T>* new_Node = new Queue<T>;
		new_Node->data = a1;
		if (front == NULL) {
			front = rear = new_Node;
			rear->next = NULL;
			size++;
		}
		else {
			//now if the the queue is not empty
			rear->next = new_Node;
			rear = new_Node;
			rear->next = NULL;
			size++;
		}
	}
	Queue<T>* gfront()
	{
		return front;
	}
	bool is_empty()
	{
		if (size == 0)
		{
			return true;
		}
		else
			return false;
	}
	void dequeue()
	{
		if (front == NULL)
			return;
		Queue<T>* tfront = new Queue<T>;
		tfront = front;
		front = front->next;
		if (front == NULL)
		{
			rear = NULL;
		}
		size--;
		delete tfront;
	}
	int gsize()
	{
		return size;
	}
	void Display()
	{
		Queue<T>* tfront = front;
		int temp = gsize();
		while (temp != 0)
		{
			cout << tfront->data << " ";
			tfront = tfront->next;
			temp--;
		}
	}
};
//implementation of the link list
template <class T>
class node
{
public:
	T data;
	node<T>* next;
	node()
	{
		next = NULL;
		data = 0;
	}
};
template<class a>
class stacklist
{
public:
	node<a>* top;
	stacklist()
	{
		top = NULL;
	}
	//now the funcitons
	void push(a pushdata)
	{
		node<a>* new_Node = new node<a>;

		new_Node->next = top;
		new_Node->data = pushdata;
		top = new_Node;
	}

	node<int>* Peek()
	{
		if (top != NULL)
		{
			return top;
		}
		else
			cout << "STACK IS EMPTY" << endl;
	}

	a pop()
	{
		a ret;
		if (top == NULL)
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			node<a>* newnode = top;
			ret = top->data;
			//newnode = top;

			top = top->next;

			newnode->next = NULL;

			delete newnode;
		}
		return ret;
	}
	int sizeQueu()
	{
		node<a>* temp = top;
		int s = 0;
		while (temp != NULL)
		{
			s++;
			temp = temp->next;
		}
		return s;
	}
	bool isEmpty()
	{
		if (top == NULL)
			return 1;
		else
			return 0;
	}
	a topele()
	{
		node<a>* temp = top;
		return temp->data;
	}
};
template <class T>
class AdjencencyList
{

public:
	node<T>* head;
	AdjencencyList()
	{
		head = NULL;
	}
	void insert(T temp)
	{
		if (head == NULL)
		{
			node<T>* new_Node = new node<T>;
			new_Node->data = temp;
			new_Node->next = NULL;
			head = new_Node;
		}
		else
		{
			node<T>* iterate = head;
			while (iterate->next != NULL)
				iterate = iterate->next;

			node<T>* new_Node = new node<T>;
			new_Node->data = temp;
			new_Node->next = NULL;
			iterate->next = new_Node;
		}
	}
	void display()
	{
		node<T>* iterate = head;
		while (iterate != NULL)
		{
			cout << iterate->data << "    ";
			iterate = iterate->next;
		}
		cout << endl;

	}
	node<T>* gethead()
	{
		return head;
	}
};

template <class T>
struct adjacencyMatrix
{
	AdjencencyList<T> objAdjList;
	T valueofnode;
};


//making the link list of a  link list to store the distributions of indegree and outdegree

template <class T>
class Node_Link_Node
{
public:
	int count;
	double ProbabilityofEachNode;
	int distvalue;
	Node_Link_Node<T>* nextNLN;
	Node_Link_Node()
	{
		nextNLN = NULL;
		count = 0;
		distvalue = 0;
		ProbabilityofEachNode = 0;
	}
};


template <class T>
class NLDClass 
{
public:
	Node_Link_Node<T>* heading;
	NLDClass()
	{
		heading = NULL;
	}
	//function to insert data in the link list of the distribution
	void insertNLD(T degree)
	{
		if (heading == NULL)
		{
			Node_Link_Node<T>* newNode = new Node_Link_Node<T>;
			newNode->distvalue = degree;
			newNode->count++;
			newNode->nextNLN = NULL;
			heading = newNode;
		}
		else
		{
			Node_Link_Node<T>* iterate = heading;
			Node_Link_Node<T>* temp = NULL;
			while (iterate != NULL && iterate->distvalue!=degree)
			{
				temp = iterate;
				iterate = iterate->nextNLN;
			}
			if (iterate!=NULL)
			{
				iterate->count++;
			}
			else
			{
				Node_Link_Node<T>* newNode = new Node_Link_Node<T>;
				newNode->distvalue = degree;
				newNode->count++;
				newNode->nextNLN = NULL;
				temp->nextNLN= newNode;
			}
		}
	}
	void displayProbdistribution()
	{
		Node_Link_Node<T>* iterate = heading;
		cout << "Degree Nodes" << "	" << "DEGREE DISTRIBUTION" << endl;
		while (iterate->nextNLN != NULL)
		{
			cout << iterate->distvalue << "	:	" << iterate->ProbabilityofEachNode << endl;
			iterate = iterate->nextNLN;
		}
		cout << iterate->distvalue << "	:	" << iterate->ProbabilityofEachNode << endl;
	}
	void CalculateProbability(T nodes)
	{
		Node_Link_Node<T>* newNode = heading;
		while (newNode != NULL)
		{
			newNode->ProbabilityofEachNode= double(newNode->count) / nodes;
			newNode = newNode->nextNLN;
		}
	}
	void Search(T node)
	{
		Node_Link_Node<T>* newNode = heading;
		while (newNode!=NULL && newNode->distvalue!=node)
		{
			newNode = newNode->nextNLN;
		}
		if (newNode != NULL)
		{
			cout << "The Indegree Distribution of Nodes having inegree/outdegree, " << node <<" is  :"<< newNode->ProbabilityofEachNode << endl;
		}
		else
		{
			cout << "Cant Find the distribution value" << endl;
		}
		
	}
};


//now the class of the graph

NLDClass<int> storeoutdegree;
NLDClass<int> storeIndegree;

template<class T>
class DirectedGraph
{
private:
	adjacencyMatrix<T>* graphnode;
	int TotalNumberOfNodesinGraph;
public:
	void BuildGraph(T t_size)
	{
		graphnode = new adjacencyMatrix<T>[t_size];
		TotalNumberOfNodesinGraph = t_size;
		for (int i = 0; i < t_size; i++)
		{
			graphnode[i].objAdjList.head = NULL;
			graphnode[i].valueofnode = 0;
		}
	}
	int checkRepetition(T searchElement)
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			if (searchElement == graphnode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	int checkemptyindex()
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			if  (graphnode[i].valueofnode==0)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void insertEdge(T t_source, T t_destination)
	{
		int index = checkRepetition(t_source);
		if (index>=0)
		{
			graphnode[index].valueofnode = t_source;
			graphnode[index].objAdjList.insert(t_destination);
		}
		else
		{
			int Eindex = checkemptyindex();

			if (Eindex == -1)
				cout << "Graph is FULL" << endl;
			else
			{
				graphnode[Eindex].valueofnode = t_source;
				graphnode[Eindex].objAdjList.insert(t_destination);
			}
		}
	}
	void showGraphStruct()
	{
		int nvert = TotalNumberOfNodesinGraph;
		cout << "Adjacency List\thead->Vertices\n";
		for (int i = 0; i < nvert; i++)
		{
			cout << graphnode[i].valueofnode << ":";
			graphnode[i].objAdjList.display();
		}
	}
	void DisplayTotalNode()
	{
		cout << "TOTAL Number of Nodes in Graph is : ";
		cout << TotalNumberOfNodesinGraph << endl;
	}
	int calculateNumberofEdges()
	{
		int countNumberOfEdges = 0;
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			countNumberOfEdges += 1;
			node<T>* temp=graphnode[i].objAdjList.gethead();
			while (temp->next != NULL)
			{
				countNumberOfEdges += 1;
				temp = temp->next;
			}
		}
		return countNumberOfEdges;
	}
	void DisplaySourceNodes()
	{
		int TotalNumberOfSourceNodes = 0;
		T check;
		for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
		{
			check = graphnode[j].valueofnode;
			bool indegree = false;
			for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			{
				node<T>* temp = graphnode[i].objAdjList.gethead();
				while (temp!= NULL)
				{
					if (check == temp->data)
					{
						indegree = true;
						break;
					}
					temp = temp->next;
				}
				if (indegree)
					break;
				else 
					continue;
			}
			if (!indegree)
			{
				cout << graphnode[j].valueofnode << endl;
				TotalNumberOfSourceNodes += 1;
			}	
		}
		cout << "Total Number of Source Nodes Are : " << TotalNumberOfSourceNodes << endl;
	}
	//function to show the number of sink nodes
	void DisplayNumberOfSinkNodes()
	{
		int TotalNumberOfSinkNodes=0;
		
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			bool outdegree = false;
			node<T>* temp = graphnode[i].objAdjList.gethead();
			if (temp != NULL)
			{
				outdegree = true;
			}
			else
			{
				outdegree = false;
			}
			if (!outdegree)
			{
				TotalNumberOfSinkNodes += 1;
			}
		}
		cout << "Total Number of Sink Nodes in Graph is : " << TotalNumberOfSinkNodes << endl;
	}
	int returnIndex(T searchnode)
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{

			if (searchnode == graphnode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void OutDegreeDistribution()
	{
		int outdegree=0;
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
		{
			outdegree = 0;
			node<T>* temp = graphnode[i].objAdjList.gethead();
			while (temp != NULL)
			{
				outdegree++;
				temp = temp->next;
			}
			storeoutdegree.insertNLD(outdegree);
		}
	}
	void IndegreeDistribution()
	{
		int TotalNumberOfSourceNodes = 0;
		T check;
		for (int j = 0; j < TotalNumberOfNodesinGraph; j++)
		{
			check = graphnode[j].valueofnode;
			int indegree = 0;
			for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			{
				node<T>* temp = graphnode[i].objAdjList.gethead();
				while (temp != NULL)
				{
					if (check == temp->data)
					{
						indegree +=1;
						break;
					}
					temp = temp->next;
				}
			}
			storeIndegree.insertNLD(indegree);
		}
	}
	void show()
	{
		for (int i = 0; i < TotalNumberOfNodesinGraph; i++)
			cout << graphnode[i].valueofnode << endl;
	}
	T getTotalNodes()
	{
		return TotalNumberOfNodesinGraph;
	}
};


//implementation of undirected graph

template<class T>
class UndirectedGraph 
{
	adjacencyMatrix<T>* undirectedGraphNode;
	int TotalNumberofNodesUndirectedGraph;
public:
	void BuildGraph(T t_size)
	{
		undirectedGraphNode = new adjacencyMatrix<T>[t_size];
		TotalNumberofNodesUndirectedGraph = t_size;
		for (int i = 0; i < t_size; i++)
		{
			undirectedGraphNode[i].objAdjList.head = NULL;
			undirectedGraphNode[i].valueofnode = 0;
		}
	}
	int checkRepetition(T searchElement)
	{
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			if (searchElement == undirectedGraphNode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	int checkemptyindex()
	{
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			if (undirectedGraphNode[i].valueofnode == 0)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void insertEdgeUndirectedGraph(T tsrc,T tdest)
	{

		insertUnDirected(tsrc, tdest);
		insertUnDirected(tdest, tsrc);
	}
	//insertion function in the undirected graph
	void insertUnDirected(T t_source,T t_destination)
	{
		int index = checkRepetition(t_source);
		if (index >= 0)
		{
			node<T>* temp = undirectedGraphNode[index].objAdjList.gethead();
			bool NodeInList = false;
			while (temp != NULL)
			{
				if (temp->data == t_destination)
				{
					NodeInList = true;
					break;
				}
				temp = temp->next;
			}
			if (!NodeInList)
			{
				undirectedGraphNode[index].valueofnode = t_source;
				undirectedGraphNode[index].objAdjList.insert(t_destination);
			}
			else
				return;
		}
		else
		{
			int Eindex = checkemptyindex();
			if (Eindex == -1)
				cout << "Graph is FULL" << endl;
			else
			{
				undirectedGraphNode[Eindex].valueofnode = t_source;
				undirectedGraphNode[Eindex].objAdjList.insert(t_destination);
			}
		}
	}
	void DisplaySourceNodesUD()
	{
		int TotalNumberOfSourceNodes = 0;
		T check;
		for (int j = 0; j < TotalNumberofNodesUndirectedGraph ; j++)
		{
			cout << "j:"<<j << endl;
			check = undirectedGraphNode[j].valueofnode;
			bool indegree = false;
			for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
			{
				node<T>* temp = undirectedGraphNode[i].objAdjList.gethead();
				while (temp != NULL)
				{
					if (check == temp->data)
					{
						indegree = true;
						break;
					}
					temp = temp->next;
				}
				if (indegree)
					break;
				else
					continue;
			}
			if (!indegree)
			{
				cout << undirectedGraphNode[j].valueofnode << endl;
				TotalNumberOfSourceNodes += 1;
			}
		}
		cout << "Total Number of Source Nodes Are : " << TotalNumberOfSourceNodes << endl;
	}
	int returnIndex(T searchnode)
	{
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			
			if (searchnode == undirectedGraphNode[i].valueofnode)
			{
				return i;
			}
			else
				continue;
		}
		return -1;
	}
	void BFS(T startnode)
	{
		//creating array of bool
		bool* Visit_array = new bool[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			Visit_array[i] = false;
		}

		tunnel<int> queue;
		int atindex = returnIndex(startnode);
		cout << startnode << endl;
		Visit_array[atindex] = true;

		queue.enqueue(startnode);
		while (!queue.is_empty())
		{	
			startnode = returnIndex(queue.gfront()->data);
			cout << queue.gfront()->data<< "  ";
			queue.dequeue();
			node<int>* temp = undirectedGraphNode[startnode].objAdjList.gethead();
			if (temp == NULL)
				cout << "sink:: " << undirectedGraphNode[startnode].valueofnode << endl;
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (Visit_array[i] == false)
				{
					Visit_array[i] = true;
					queue.enqueue(temp->data);
				}
				temp = temp->next;
			}
		}
	}

	void DFSearch(T startnode)
	{
		
		//creating array of bool
		bool* Visit_array = new bool[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			Visit_array[i] = false;
		}

		stacklist<T> stackp;
		int atindex = returnIndex(startnode);
		cout << startnode << endl;
		Visit_array[atindex] = true;

		stackp.push(startnode);
		while (!stackp.isEmpty())
		{
			startnode = returnIndex(stackp.Peek()->data);
			cout << stackp.Peek()->data<<" ";
			stackp.pop();
			node<int>* temp = undirectedGraphNode[startnode].objAdjList.gethead();
			if (temp == NULL)
				cout << "sink:: " << undirectedGraphNode[startnode].valueofnode << endl;
			while (temp != NULL)
			{
				int i = returnIndex(temp->data);
				if (Visit_array[i] == false)
				{
					Visit_array[i] = true;
					stackp.push(temp->data);
				}
				temp = temp->next;
			}
		}
	}
	//showing the number of the graph nodes
	void showGraphStruct()
	{
		int nvert = TotalNumberofNodesUndirectedGraph;
		cout << "Adjacency List\thead->Vertices\n";
		for (int i = 0; i < nvert; i++)
		{
			cout << undirectedGraphNode[i].valueofnode << ":";
			undirectedGraphNode[i].objAdjList.display();
		}
	}
	//calculating the nummber of bridges
	void calculateBridgeEdges(int source_vertex,bool* visiting_array,int* discTime,int* lowcheck,int* parent)
	{	
		cout << "Here" << endl;
		static int time_t = 0;
		int atindex = returnIndex(source_vertex);
		//marking the visiting node as visited
		visiting_array[atindex] = true;
		//now initializing the discovery and low value for that vertex in a graph
		time_t+=1;
		discTime[atindex] = time_t;
		//now intiitalizing the low index with time
		lowcheck[atindex] = time_t;

		//now checking the adjacent vertices of the graph

		node<T>* iteratepointer = undirectedGraphNode[atindex].objAdjList.gethead();
		while (iteratepointer != NULL)
		{
			int i = returnIndex(iteratepointer->data);
			if (visiting_array[i] == false)
			{
				parent[i] = source_vertex;
				calculateBridgeEdges(iteratepointer->data,visiting_array,discTime,lowcheck,parent);
				lowcheck[atindex] = min(lowcheck[atindex], lowcheck[i]);
				if (lowcheck[i] > discTime[atindex])
				{
					cout << "Bridge Edges Are: " << endl;
					cout << source_vertex << iteratepointer->data << endl;
				}

			}
			else if (iteratepointer->data != parent[i])
			{
				lowcheck[atindex] = min(lowcheck[atindex], discTime[i]);
			}

		}
	}
	void BridgeEdges()
	{
		bool* visiting_array = new bool[TotalNumberofNodesUndirectedGraph];
		int* discTime = new int[TotalNumberofNodesUndirectedGraph];
		int* lowcheck = new int[TotalNumberofNodesUndirectedGraph];
		int* parent = new int[TotalNumberofNodesUndirectedGraph];
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			parent[i] = 0;
			visiting_array[i] = false;
		}

		//now calling th calc bridge funciton
		for (int i = 0; i < TotalNumberofNodesUndirectedGraph; i++)
		{
			if (visiting_array[i] == false)
			{
				calculateBridgeEdges(undirectedGraphNode[i].valueofnode, visiting_array, discTime, lowcheck, parent);
			}
		}

	}
};




DirectedGraph<int> Gobj;
UndirectedGraph<int> UndirectedGraphObject;
//file reading code

void DataFetch(string filepath)
{
	fstream objFile;
	int countLine = 0;
	string NumberOfEdges = "";
	string NumberOfNodes = "";
	bool flag1 = true;
	bool flag2 = true;
	objFile.open(filepath);
	while (!objFile.eof())
	{
		countLine += 1;
		string ReadDataFromFile = "";
		//to store number of nodes and no of edges on line file 3
		string iterate_source = "";
		string iterate_dest = "";
		//reading one line
		getline(objFile, ReadDataFromFile);
		//For the nodes and edges
		//if string is not empty
		if (ReadDataFromFile != "")
		{
			if (countLine == 3)
			{
				for (int i = 0; i < ReadDataFromFile.length(); i++)
				{
					if (ReadDataFromFile[i] == ':' && flag1 == true)
					{
						i += 2;
						while (ReadDataFromFile[i] != ' ')
						{
							NumberOfNodes += ReadDataFromFile[i];
							i++;
						}
						flag1 = false;
					}
					if (ReadDataFromFile[i] == ':' && flag2 == true)
					{
						i += 2;
						while (i != ReadDataFromFile.length())
						{
							NumberOfEdges += ReadDataFromFile[i];
							i++;
						}
						flag2 = false;
					}
				}
				Gobj.BuildGraph(stoi(NumberOfNodes));
				UndirectedGraphObject.BuildGraph(stoi(NumberOfNodes));
			}
			if (countLine > 4)
			{
				bool checkspace = false;
				for (int i = 0; i < ReadDataFromFile.length(); i++)
				{
					while (ReadDataFromFile[i] != '	')
					{

						iterate_source += ReadDataFromFile[i];
						i++;
					}
					if (ReadDataFromFile[i] == '	')
					{
						i++;
						while (i != ReadDataFromFile.length())
						{
							iterate_dest += ReadDataFromFile[i];
							i++;
						}
					}
				}
				Gobj.insertEdge(stoi(iterate_source), stoi(iterate_dest));
				UndirectedGraphObject.insertEdgeUndirectedGraph(stoi(iterate_source), stoi(iterate_dest));
			}
			else
				continue;
		}
	}
	//closing the file
	objFile.close();
}

int main()
{
	cout << "Inserting Data Into Graph." << endl;
	string path = "C:\\Users\\Butt\\Desktop\\1.txt";
	DataFetch(path);
	cout << "Inserted Successfuly" << endl;
	cout << endl;
	string input;
	do 
	{
		input = "";
		cout << "			"<<"Menu" << endl;
		cout << endl;
		cout << "1. Display the number of nodes(5 marks)" << endl;
		cout << "2. Display the number of edges(5 marks)" << endl;
		cout << "3. Display the number of source nodes(5 marks)" << endl;
		cout << "4. Display the number of sink nodes(5 marks)" << endl;
		cout << "10. Display the in - degree distribution in the form of a table(10 marks)"<<endl;
		cout << "11. Display the out - degree distribution in the form of a table(10 marks) "<< endl;
		cout << "Choose from Above Options or enter q to quit" << endl;
		cin >> input;
		if (input == "1")
		{
			cout << "You have choosen option 1: " << endl;
			Gobj.DisplayTotalNode();
		}
		else if (input == "2")
		{
			cout << Gobj.calculateNumberofEdges() << endl;
		}
		else if (input == "3")
		{
			Gobj.DisplaySourceNodes();
		}
		else if (input == "4")
		{
			Gobj.DisplayNumberOfSinkNodes();
		}
		else if (input == "10")
		{
			cout << "Calculating Indegree Disbtribution..." << endl;
			Gobj.IndegreeDistribution();
			storeIndegree.CalculateProbability(Gobj.getTotalNodes());
			cout << endl;
			cout << "Calculated Successfuly" << endl;
			string input2="";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storeIndegree.displayProbdistribution();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storeIndegree.Search(serchdist);
			}
		}
		else if (input == "11")
		{
			cout << "Calculating outdegreedegree Disbtribution..." << endl;
			Gobj.OutDegreeDistribution();
			storeoutdegree.CalculateProbability(Gobj.getTotalNodes());
			cout << endl;
			cout << "Calculated Successfuly" << endl;
			string input2 = "";
			cout << "1. You want to display the whole distribution table." << endl;
			cout << "2. You want to search in the distribution table." << endl;
			cin >> input2;
			if (input2 == "1")
			{
				storeoutdegree.displayProbdistribution();
			}
			else if (input2 == "2")
			{
				int serchdist;
				cout << "Enter the value of distribution you want to search in distribution table. " << endl;
				cin >> serchdist;
				storeoutdegree.Search(serchdist);
			}
		}

	} while (input != "q");

}
