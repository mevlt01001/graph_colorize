#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <random>
class node;
class  graph;
void freeMemory(graph* gr);
class graph{
public:
    std::vector<node*> vertexes;
    std::stack<node*> stack;
    ~graph(){
        freeMemory(this);
    }
};
class node{
public:
    std::vector<node*> adj;
    std::vector<std::string> usableColors;

    std::string color = "none";
    bool inStack = false;
    int position = 0;

    node(int pos){
        this->position = pos;
    }
};

void createNodes(graph* gr, std::vector<int>& vertexes){
    for(auto i : vertexes){
        node* vertex = new node(i);
        gr->vertexes.insert(gr->vertexes.end(),vertex);
    }
}

node* findVertex(graph* gr, int position){
    for(auto vertex : gr->vertexes){
        if(vertex->position == position){
            return vertex;
        }
    }
    return nullptr;
}

void setAdj(graph* gr, std::map<int,std::vector<int>>& vertexesAndItsAdj){
    for(auto& map : vertexesAndItsAdj){
        node* vertex = findVertex(gr, map.first);
        for(auto adj : map.second){
            vertex->adj.insert(vertex->adj.end(), findVertex(gr, adj));
        }
    }
}

std::string usableColor(node* vertex, std::vector<std::string>& colors){
    std::vector<std::string> tempColors = colors;
    for(auto adj : vertex->adj){
        auto item = std::find(tempColors.begin(),tempColors.end(),adj->color);
        if(item != tempColors.end()){
            tempColors.erase(item);
        }
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, tempColors.size()-1);
    if(!(tempColors.empty())){
        for(auto& i: tempColors){
            vertex->usableColors.insert(vertex->usableColors.end(),i);
        }
        return tempColors[dis(gen)];
    }
    return "none";
}

void painting(graph* gr, node* vertex, std::vector<std::string>& colors){
    vertex->color = usableColor(vertex,colors);
    for(auto edge : vertex->adj){
        if(!edge->inStack){
            gr->stack.push(edge);edge->inStack = true;
        }
    }
}

node* nextNodeInStack(graph* gr, node* vertex){
    std::stack<node*> tempStack = gr->stack;
    node* nextVertex = nullptr;
    while(!tempStack.empty()){
        if(tempStack.top() == vertex){
            break;
        }
        nextVertex = tempStack.top();
        tempStack.pop();;;
    }
    return nextVertex;
}

void graphColorize(graph* gr, std::vector<std::string>& colors){
    for(auto i : gr->vertexes){
        i->color = "none";
    }
    std::stack<node*> stack = gr->stack;
    node* vertex = findVertex(gr,5);
    while(vertex != nullptr){
        painting(gr, vertex, colors);
        vertex = nextNodeInStack(gr, vertex);
    }
}

void showGraph(graph* gr){
    for(auto i : gr->vertexes){
        std::cout<<"vertex("<<i->position<<"):"<<i->color<<"\t| Adjs:";
        for(auto edge : i->adj){
            std::cout<<" - vertex("<<edge->position<<"):"<<edge->color;
        }
        std::cout<<std::endl;
    }
}

void freeMemory(graph* gr){
    for(auto i : gr->vertexes){
        delete i;
    }
}

int main(){
    std::vector<int> vertexesPositions = {1,2,3,4,5,6,7,8,9};
    std::vector<std::string> colors = {"Red", "Green", "Blue"};
    std::map<int, std::vector<int>> vertexesAndEdges = {
            {1,{2,4}},
            {2,{1,3,4,5,6}},
            {3,{2,6}},
            {4,{1,2,7}},
            {5,{2,6,7,8,9}},
            {6,{2,3,5,9}},
            {7,{4,5}},
            {8,{5,9}},
            {9,{5,6,8}}
    };
    graph* gr = new graph();
    createNodes(gr, vertexesPositions);
    setAdj(gr, vertexesAndEdges);
    graphColorize(gr, colors);
    showGraph(gr);
    delete gr;
}
