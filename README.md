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
