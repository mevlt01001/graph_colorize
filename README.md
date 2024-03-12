# graph_colorize

QUESTION:

Write a function called graphColorize that assigns colors to the nodes of an undirected graph so that neighboring nodes are not the same color. 

Input: (Graph &graph, vector<string> &colors) 

![image](https://github.com/mevlt01001/graph_colorize/assets/114837266/16ba4abb-3327-4e58-a8b7-4f48b2d883b0)


For example, given the colors {"blue", "green", "red"} to the function, the current screen output:

    {0:"blue",1:"green", 2:"blue", 3:"red",4:"blue",5:"red",6:"green",7:"red", 8:"green"}

• The graph given as an example cannot be colored correctly with less than 3 colors. But it is expected to work successfully with a value of 3 or more. 

• If there is more than one way to color the graph, the function can return any of them.

• "Graph empty" if coloring cannot be performed with the specified number of colors print it out.

• You can add elements to the graph as you like.

ANSWER.cpp Functions:
    
     createNodes --->   is used to create node objects in memory.
                        The addresses of the created objects are stored in the graph class
                        are stored in the 'vertexes' vector inside the object.
    
     findVertex ---->   Each vertex has a logical position, findVertex
                        returns the result by finding the vertex with that position.
    
     setAdj -------->   Each vertex points to other vertexes with the help of 'findVertex
                        and binds it to the vertex->adj vector of the corresponding vertex.
    
     usableColour..->   This function is used to set all colours pointed to by the vertex given as parameter to this function.
                        checks the colours assigned to its neighbours one by one and
                        returns any non-existent colour as a result.
    
     painting..----->   paints the value given as parameter using 'usableColor' and
                        adds vectors to the stack that are not in the stack it points to.
    
     nextNodeI..---->   nextNodeInStack is a function of the position of the given node in the stack.
                        Returns the address of the next element in memory, i.e. the one immediately above.
    
     graphColo..---->   graphColorize, to colour the vertex with position 5 (centre of a 9x9 square) first
                        as a parameter to the painting function, then 'nextNodeInStack' from the stack structure
                        Executes the painting function iteratively using the function.


OUTPUT:
    
    vertex(1):Green	| Adjs: - vertex(2):Red - vertex(4):Blue
    vertex(2):Red	| Adjs: - vertex(1):Green - vertex(3):Blue - vertex(4):Blue - vertex(5):Blue - vertex(6):Green
    vertex(3):Blue	| Adjs: - vertex(2):Red - vertex(6):Green
    vertex(4):Blue	| Adjs: - vertex(1):Green - vertex(2):Red - vertex(7):Red
    vertex(5):Blue	| Adjs: - vertex(2):Red - vertex(6):Green - vertex(7):Red - vertex(8):Green - vertex(9):Red
    vertex(6):Green	| Adjs: - vertex(2):Red - vertex(3):Blue - vertex(5):Blue - vertex(9):Red
    vertex(7):Red	| Adjs: - vertex(4):Blue - vertex(5):Blue
    vertex(8):Green	| Adjs: - vertex(5):Blue - vertex(9):Red
    vertex(9):Red	| Adjs: - vertex(5):Blue - vertex(6):Green - vertex(8):Green

    Process finished with exit code 0
